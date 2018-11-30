#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

class LEXTOKEN
{
    public:
    int id;
    int pri;
};

class PARSER
{
    public:
    virtual void Parse(int input_str[]) = 0;
};

class ARITH: public PARSER
{
    public:
    void Parse(int input_str[]);
};

void SortStack(void);
extern LEXTOKEN Tokstack[20];
extern int toktop;
extern int read_num;

#endif // PARSER_H_INCLUDED
