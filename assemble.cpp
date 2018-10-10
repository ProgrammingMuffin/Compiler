#include<iostream>
#include<fstream>
#include "assemble.h"

int opcodes[5] = {

    1,
    2,
    3,
    4,
    5

};

std::string ops[5] = {

    "ADD",
    "ADDX",
    "MOV",
    "STA",
    "LDA"

};

Symbol_Table SYMTAB;
Opcode_Table OPTAB(ops, opcodes, 5);

void OpenFile(std::string file_name)
{
    codefile.open(file_name.c_str(), std::ios::in);
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
        std::cout<<"Entry "<<i+1<<":\tSymbol: "<<symbol[i]<<"\tValue: "<<value[i]<<"\tRange: "<<range[i]<<std::endl;
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
    std::cout<<"\n\tDisplaying all values inside OPTAB\n\n"<<std::endl;
    for(i=0;i<this->optab_size;i++)
    {
        std::cout<<"Entry "<<i+1<<": "<<op[i]<<"\t"<<opcode[i]<<std::endl;
    }
}
