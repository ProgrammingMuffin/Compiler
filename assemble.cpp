#include<iostream>
#include<fstream>
#include "assemble.h"

int opcodes[21] = {

    24,
    64,
    40,
    36,
    48,
    52,
    56,
    72,
    0,
    104,
    80,
    4,
    32,
    68,
    76,
    12,
    120,
    84,
    16,
    28,
    44

};

std::string ops[21] = {

    "ADD",
    "AND",
    "COMP",
    "DIV",
    "JEQ",
    "JGT",
    "JLT",
    "JSUB",
    "LDA",
    "LDB",
    "LDCH",
    "LDX",
    "MUL",
    "OR",
    "RSUB",
    "STA",
    "STB",
    "STCH",
    "STX",
    "SUB",
    "TIX"

};

Symbol_Table SYMTAB;
Opcode_Table OPTAB(ops, opcodes, 5);

void OpenFile(std::string file_name)
{
    codefile.open(file_name.c_str(), std::ios::in);
}

void Tokenize(std::string line, std::string *label, std::string *mnem, std::string *arg)
{
    int i;
    for(i=0;i<(int)line.length() && line[i]!=' ';i++)
    {
        label->push_back(line[i]);
    }
    if(OPTAB.Search(*label) >= 0)
    {
        mnem = label;
        i++;
        while(i<(int)line.length() && line[i]!=',')
            arg->push_back(line[i++]);
        if(line[i]==',')
        {
            i++;
            while(i<(int)line.length())
                mnem->push_back(line[i]);
        }
    }
    else
    {
        i++;
        while(i<(int)line.length() && line[i]!=' ')
            mnem->push_back(line[i++]);
        i++;
        while(i<(int)line.length() && line[i]!=',')
            arg->push_back(line[i++]);
        if(line[i]==',')
        {
            i++;
            while(i<(int)line.length())
                mnem->push_back(line[i]);
        }
    }
}

void BufferCode()
{
    std::string mnem, label, arg;
    std::string line = ReadSourceLine();
    Tokenize(line, &label, &mnem, &arg);
    std::cout<<"Line is: "<<label<<"\t"<<mnem<<"\t"<<arg<<std::endl;
}

/*void Scan(std::string line)
{
}
*/
std::string ReadSourceLine()
{
    std::string line;
    std::getline(codefile, line);
    return line;
}

void Symbol_Table::Push(std::string sym, int loc, int s)
{
    top++;
    symbol[top] = sym;
    value[top] = loc;
    range[top] = s;
}

int Symbol_Table::Search(std::string sym)
{
    int pos = -1, i;
    for(i=0;i<=top;i++)
    {
        if(symbol[i] == sym)
        {
            pos = i;
        }
    }
    return pos;
}

void Symbol_Table::Display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        //symbol[i] = "HAHAHAA";
        //std::cout<<"Entry "<<i+1<<":\tSymbol: "<<symbol[i]<<"\tValue: "<<value[i]<<"\tRange: "<<range[i]<<std::endl;
    }
}

void AddDefaultSymbol(void)
{
    SYMTAB.Push("Hello World", 6860112, 98);
    std::cout<<"Jesus Christ"<<std::endl;
}

Opcode_Table::Opcode_Table(std::string op[], int opcode[], int n)
{
    int i;
    this->optab_size = n;
    for(i=0;i<n;i++)
    {
        this->op[i] = op[i];
        this->opcode[i] = opcode[i];
    }
}

void Opcode_Table::Display(void)
{
    int i;
    //std::cout<<"\n\tDisplaying all values inside OPTAB\n\n"<<std::endl;
    for(i=0;i<this->optab_size;i++)
    {
        //std::cout<<"Entry "<<i+1<<": "<<op[i]<<"\t"<<opcode[i]<<std::endl;
    }
}

int Opcode_Table::Search(std::string sym)
{
    int i, pos=-1;
    for(i=0;i<optab_size;i++)
    {
        if(this->op[i]==sym)
            pos = i;
    }
    return pos;
}
