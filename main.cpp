#include<iostream>
#include<fstream>
#include "loader.h"
#include "assemble.h"
#include "CEE.h"
#include "parser.h"
#include "lexer.h"

std::fstream codefile;
std::ofstream objfile;
ARITH a;
unsigned int CMEM[200], ACC, IR[2];
unsigned long int LEN=0;
int PC, AMEM[200], DMEM[200];
int CMEM_ptr = 0, AMEM_ptr = 0, DMEM_ptr = 0;

int main( )
{
    int x[6] = {5, 6, 5, 7, 5, 10};
    unsigned long int temp;
    OpenFile("test.sic");
    //Pass1();
    //Pass2();
    //std::cout<<"\nFrom loaded file: \n"<<std::endl;
    //LoadProgram("test.obj");
    //PrintMemory();
    temp = LEN;
    //std::cout<<"LEN value is: "<<LEN<<std::endl;
    /*while(temp)
    {
        temp--;
        Fetch();
        Execute();
        PrintMemory();
    }*/
    //a.Parse(x);
    NebScan();
    //std::cout<<"\n\n\tTOK_VAR object: "<<TOK_VAR.id<<std::endl;
    /*while(!codefile.eof())
    {
        std::string line = ReadSourceLine();
        std::cout<<"The line is: "<<line<<std::endl;
    }*/
    //OPTAB.Display();
    return 0;
}
