#include<iostream>
#include<string>
#include<fstream>
#include "assemble.h"
#include "CEE.h"
#include "loader.h"

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
        LEN++;
        CMEM[CMEM_ptr] = obj.mnem;
        CMEM_ptr++;
        AMEM[AMEM_ptr] = obj.arg;
        AMEM_ptr++;
        std::cout<<"Object Code: "<<obj.mnem<<"-"<<obj.arg<<std::endl;
    }
    codefile.close();
}

void PrintMemory()
{
    int i;
    std::cout<<"\nCode Memory: "<<std::endl;
    for(i=0;i<CMEM_ptr;i++)
        std::cout<<CMEM[i]<<std::endl;
    std::cout<<"\nArgument Memory: "<<std::endl;
    for(i=0;i<AMEM_ptr;i++)
        std::cout<<AMEM[i]<<std::endl;
    std::cout<<"\nArgument Memory: "<<std::endl;
    for(i=0;i<DMEM_ptr;i++)
        std::cout<<DMEM[i]<<std::endl;
    std::cout<<"\nAccumulator: "<<ACC<<std::endl;
}
