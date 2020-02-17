#ifndef NUMERAL_WORD_HPP
#define NUMERAL_WORD_HPP

#include <string>

class NumeralWord
{
public:
    NumeralWord(std::string repr) : _repr(repr){};
    virtual ~NumeralWord(){};
    virtual int evaluate() = 0;
    virtual void setChild(NumeralWord *child) = 0;
    virtual std::string to_string() = 0;

protected:
    std::string _repr;
};

#endif // !NUMERAL_WORD_HPP
