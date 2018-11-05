#include<iostream>
#include<fstream>
#include "assemble.h"
#include "loader.h"

std::fstream codefile;
std::ofstream objfile;

int main( )
{
    OpenFile("test.sic");
    Pass1();
    Pass2();
    std::cout<<"\nFrom loaded file: \n"<<std::endl;
    LoadProgram("test.obj");
    /*while(!codefile.eof())
    {
        std::string line = ReadSourceLine();
        std::cout<<"The line is: "<<line<<std::endl;
    }*/
    //OPTAB.Display();
    return 0;
}
