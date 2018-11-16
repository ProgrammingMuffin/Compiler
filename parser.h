#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

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

#endif // PARSER_H_INCLUDED
