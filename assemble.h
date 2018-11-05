#include <iostream>

#ifndef ASSEMBLE_H_INCLUDED
#define ASSEMBLE_H_INCLUDED

class Symbol_Table
{
    std::string symbol[200];
    int value[200];
    int range[200];
    int type[200];
    int top;
    public:
        Symbol_Table()
        {
            top = -1;
        }
        void Push(std::string sym, int loc, int s, int dtype=0);
        int Search(std::string sym);
        int GetValue(int pos);
        int GetRange(int pos);
        int GetType(int pos);
        void Display();
};

class Opcode_Table
{
    std::string op[21];
    unsigned int opcode[21];
    int optab_size;
    public:
        Opcode_Table(std::string op[], unsigned int opcode[], int n);
        Opcode_Table(){ }
        int Search(std::string sym);
        unsigned int GetOpcode(int pos);
        void Display(void);
};

class OBJECTCODE
{
    public:
        unsigned int mnem;
        int arg;
};

extern std::fstream codefile;
extern std::ofstream objfile;
extern Symbol_Table SYMTAB;
extern Opcode_Table OPTAB;
extern unsigned long int LOCCTR;

//void Scan();
void Tokenize(std::string, std::string*, std::string*, std::string*);
long int stoi(std::string);
void AddDefaultSymbol(void);
void OpenFile(std::string);
void Pass1();
void Pass2();
std::string ReadSourceLine();

#endif // ASSEMBLE_H_INCLUDED
