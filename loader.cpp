#include<iostream>
#include<string>
#include<fstream>
#include "assemble.h"

void LoadProgram(std::string file_name)
{
    OBJECTCODE obj;
    codefile.open(file_name.c_str(), std::ios::in | std::ios::binary);
    while(true)
    {
        codefile.read((char*)&obj, sizeof(obj));
        if(codefile.eof())
            break;
        //Loader code here:

        std::cout<<"Object Code: "<<obj.mnem<<"-"<<obj.arg<<std::endl;
    }
    codefile.close();
}
