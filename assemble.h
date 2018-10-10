#include <iostream>

#ifndef ASSEMBLE_H_INCLUDED
#define ASSEMBLE_H_INCLUDED

class Symbol_Table
{
    std::string symbol[200];
    int value[200];
    int range[200];
    int top;
    public:
        Symbol_Table()
        {
            top = -1;
        }
        void Push(std::string sym, int loc, int s);
        int Search(std::string sym);
        void Display();
};

class Opcode_Table
{
    std::string op[18];
    int opcode[18];
    int optab_size;
    public:
        Opcode_Table(std::string op[], int opcode[], int n);
        Opcode_Table(){ }
        void Display(void);
};

extern std::fstream codefile;
extern Symbol_Table SYMTAB;
extern Opcode_Table OPTAB;

//void Scan();
//void Tokenize();
void AddDefaultSymbol(void);
void OpenFile(std::string);
std::string ReadSourceLine();

#endif // ASSEMBLE_H_INCLUDED
