#include<iostream>
#include<fstream>
#include "lexer.h"

/*Token types and it's equivalent meanings:

Type        Meaning

0           identifier
1           digit
2           keyword_int
3           semi_colon
4           ( brace
5           ) brace
6           keyword_declare

*/

TOKEN TOK_POOL[50];
int POOLTOP = -1;

void NebScan()
{
    TOKEN temp;
    int state=0;
    int lexed = 0;
    int lexed_var = 0;
    int i=0;
    char ch;
    std::ifstream nebsource("main.n");
    std::string LexemeBuffer;
    //std::string TempBuffer;
    refetch:
    std::getline(nebsource, LexemeBuffer);
    //TempBuffer = LexemeBuffer;
    while(i < (int)LexemeBuffer.length())
    {
        ch = LexemeBuffer[i];
        Lex(temp, ch, state, lexed, lexed_var);
        std::cout<<"ch: "<<ch<<"\tstate: "<<state<<"\tlexed: "<<lexed<<std::endl;
        if(lexed == 1)
        {
            lexed = 0;
            lexed_var = 0;
            state = 0;
            TOK_POOL[++POOLTOP] = temp;
            temp.id.clear();
            std::cout<<"Variable token has been found!"<<std::endl;
        }
        i++;
    }
    if(!nebsource.eof())
        goto refetch;
    else
        goto no_refetch;
    no_refetch:
    for(int j=0;j<=POOLTOP;j++)
    {
        std::cout<<"Token "<<j+1<<": "<<TOK_POOL[j].id<<"\tType: ";
        if(TOK_POOL[j].type == 0)
            std::cout<<"identifier"<<std::endl;
        else
            std::cout<<"others"<<std::endl;
    }
    return;
}

void Lex(TOKEN &t, char ch, int &state, int &lexed, int &lexed_var)
{
    if(lexed == 0)
    {
        t.type = 0;
        switch(state)
        {
            case 0: switch(ch)
                    {
                        case '$':   state = 1;
                                    t.id.push_back(ch);
                                    break;
                        default:    //std::cout<<"Not a variable: "<<std::endl;
                                    state = 4;
                                    break;
                    }
                    break;
            case 1: if(isalpha(ch))
                    {
                        state = 2;
                        t.id.push_back(ch);
                    }
                    else
                    {
                        //std::cout<<"Not a variable: "<<std::endl;
                        state = 4;
                        t.id.push_back(ch);
                    }
                    break;
            case 2: if(isalnum(ch))
                    {
                        state=2;
                        t.id.push_back(ch);
                    }
                    else if(ch == ' ' || isgraph(ch))
                    {
                        lexed_var = 1;
                        lexed = 1;
                        state = 0;
                        std::cout<<"Variable Token detected!!!"<<std::endl;
                    }
                    else
                    {
                    //std::cout<<"Not a variable: "<<std::endl;
                    state = 4;
                    t.id.push_back(ch);
                    }
                    break;
            case 4: //trap state
                    state = 4;
                    t.id.push_back(ch);
                    break;
        }
    }
}
