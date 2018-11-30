#include<iostream>
#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

class TOKEN
{
    public:
    std::string id;
    int pri;
    int type;
    int int_lexval;
};

void NebScan();
void Lex(TOKEN &t, char ch, int &state, int &lexed, int &lexed_var);

#endif // LEXER_H_INCLUDED
