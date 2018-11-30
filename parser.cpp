#include "parser.h"
#include<iostream>

LEXTOKEN Tokstack[20];
int toktop = -1;
int read_num = 0;
char char_map[12] = {'e', 'E', 't', 'T', 'f', 'i', '+', '*', '(', ')', '$'};

void ARITH::Parse(int input_str[])
{
    char char_map[12] = {'e', 'E', 't', 'T', 'f', 'i', '+', '*', '(', ')', '$'};
    int PT[5][6][3] =
    {
        {
            {2, 1, 999},
            {999},
            {999},
            {2, 1, 999},
            {999},
            {999}
        },
        {
            {999},
            {6, 2, 1},
            {999},
            {999},
            {11, 999, 999},
            {11, 999, 999}
        },
        {
            {4, 3, 999},
            {999},
            {999},
            {4, 3, 999},
            {999},
            {999}
        },
        {
            {999},
            {11, 999, 999},
            {7, 4, 3},
            {999},
            {11, 999, 999},
            {11, 999, 999}
        },
        {
            {5, 999, 999},
            {999},
            {999},
            {8, 0, 9},
            {999},
            {999}
        }
    };
    int STACK[50] = {10, 0};
    int top = 1;
    int iptr = 0;
    int rptr = 0; //Reverse ptr
    int pos;
    int row, col;
    while(top >= 0 && iptr <= 5)
    {
        if(STACK[top] != 10 && STACK[top] != 11 && STACK[top] != input_str[iptr])
        {
            row = STACK[top];
            col = input_str[iptr] - 5;
            std::cout<<"\n"<<char_map[row]<<"->";
            if(PT[row][col][0] != 999)
            {
                pos = 2;
                top--;
                //std::cout<<"\nRow: "<<row<<"\tCol: "<<col<<std::endl;
                while(pos >= 0)
                {
                    if(PT[row][col][pos] != 999)
                    {
                        top++;
                        STACK[top] = PT[row][col][pos];
                        std::cout<<char_map[STACK[top]];
                        pos--;
                    }
                    else
                    {
                        pos--;
                    }
                }
            }
            std::cout<<std::endl;
        }
        else if(STACK[top] != 10 && STACK[top] != 11 && STACK[top] == input_str[iptr])
        {
            //MATCH()
            std::cout<<"\nMATCH("<<char_map[STACK[top]]<<")"<<std::endl;
            Tokstack[++toktop].id = STACK[top];
            read_num++;
            //std::cout<<"STACK IS: "<<std::endl;
            iptr++;
            top--;
            if(read_num == 3)
            {
                SortStack();
            }
            /*for(int j=0;j<=top;j++)
                std::cout<<STACK[j]<<" ";
            std::cout<<"\nInput stream: "<<std::endl;
            for(int j=iptr;j<=6;j++)
                std::cout<<input_str[j]<<" ";
            std::cout<<std::endl;
            */
        }
        else if(STACK[top] == 10 && STACK[top] != 11 && STACK[top] == input_str[iptr])
        {
            std::cout<<"\n\n\n\n\nSTRING IS ACCEPTED"<<std::endl;
            break;
        }
        else if(STACK[top] == 11)
        {
            top--;
            /*std::cout<<"STACK IS: "<<std::endl;
            for(int j=0;j<=top;j++)
                std::cout<<STACK[j]<<" ";
            std::cout<<"\nInput stream: "<<std::endl;
            for(int j=iptr;j<=6;j++)
                std::cout<<input_str[j]<<" ";
            std::cout<<std::endl;
            */
        }
        else
        {
        }
    }
}

void SortStack(void)
{
    int i, j;
    LEXTOKEN temp;
    read_num = 0;
    /*for(i=0;i<=toktop;i++)
    {
        for(j=0;j<=(toktop-i-1);j++)
        {
            if(Tokstack[j].pri > Tokstack[j+1].pri)
            {
                temp = Tokstack[j];
                Tokstack[j] = Tokstack[j+1];
                Tokstack[j+1] = temp;
            }
        }
    }*/
    std::cout<<"\n\tPriority sorted tok stack is: "<<std::endl;
    for(i=0;i<=toktop;i++)
    {
        std::cout<<"\t"<<char_map[Tokstack[i].id];
    }
    std::cout<<std::endl;
}
