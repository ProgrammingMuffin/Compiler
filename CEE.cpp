#include<iostream>
#include<fstream>
#include "CEE.h"
#include "assemble.h"
//CEE stands for Code Execution Environment (Virtual Processor)

void Executable::ADD()
{
    int val = DMEM[DMEM_ptr];
    ACC += val;
}

void Executable::SUB()
{
    int val = DMEM[DMEM_ptr];
    ACC -= val;
}

void Executable::STA()
{
    DMEM[DMEM_ptr] = ACC;
}

void Executable::LDA()
{
    int val = DMEM[DMEM_ptr];
    ACC = val;
}

void Fetch()
{
    IR[0] = CMEM[CMEM_ptr];
    IR[1] = AMEM[AMEM_ptr];
    CMEM_ptr++;
    AMEM_ptr++;
}

void Execute()
{
    Executable EXEC;
    //DMEM_ptr = (IR[1] >= SegThresh)?(IR[1] - SegThresh):IR[1];
    if(IR[1] >= SegThresh)
        DMEM_ptr = IR[1] - SegThresh;
    else
        DMEM_ptr = IR[1];
    switch(IR[0])
    {
        case 24:    EXEC.ADD();
                    std::cout<<"adding"<<std::endl;
                    break;
        case 28:    EXEC.SUB();
                    std::cout<<"subtract"<<std::endl;
                    break;
        case 12:    EXEC.STA();
                    std::cout<<"STORE TO ACC"<<std::endl;
                    break;
        case 0:     EXEC.LDA();
                    std::cout<<"LOAD TO ACC"<<std::endl;
                    break;
        default:    std::cout<<"invalid option specified"<<std::endl;
    }
}
