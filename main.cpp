#include<iostream>
#include<fstream>
#include "assemble.h"

std::fstream codefile;

int main( )
{
    //std::string line;
    /*OpenFile("test.sic");
    while(!codefile.eof())
    {
        line = ReadSourceLine();
        std::cout<<"The line is: "<<line<<std::endl;
    }*/
    OPTAB.Display();
    return 0;
}
