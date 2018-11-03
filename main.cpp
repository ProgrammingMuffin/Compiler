#include<iostream>
#include<fstream>
#include "assemble.h"

std::fstream codefile;

int main( )
{
    OpenFile("test.sic");
    Pass1();
    Pass2();
    /*while(!codefile.eof())
    {
        std::string line = ReadSourceLine();
        std::cout<<"The line is: "<<line<<std::endl;
    }*/
    //OPTAB.Display();
    return 0;
}
