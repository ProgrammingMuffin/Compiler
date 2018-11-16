#ifndef CEE_H_INCLUDED
#define CEE_H_INCLUDED

extern unsigned int CMEM[200];
extern unsigned int IR[2];
extern unsigned int ACC;
extern int AMEM[200];
extern int DMEM[200];
extern int PC;
extern int CMEM_ptr;
extern int AMEM_ptr;
extern int DMEM_ptr;

class Executable
{
    public:
    void ADD();
    void SUB();
    void STA();
    void LDA();
    //void STATIC_MEMALLOC_WORD(); // not sure about these two functions as they may not matter during run time.
    //void STATIC_MEMALLOC_BYTE();
};

void Fetch();
void Execute();

#endif // CEE_H_INCLUDED
