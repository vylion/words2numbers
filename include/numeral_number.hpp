#ifndef NUMERAL_NUMBER_HPP
#define NUMERAL_NUMBER_HPP

#include "numeral_word.hpp"

class NumeralNumber : public virtual NumeralWord
{
public:
    NumeralNumber(std::string repr, NumeralWord *child, int value) : NumeralWord(repr), _power(child), _value(value){};
    NumeralNumber(std::string repr, int value) : NumeralNumber(repr, nullptr, value){};
    ~NumeralNumber();
    void setChild(NumeralWord *child);
    int evaluate();
    std::string to_string();

private:
    NumeralWord *_power;
    int _value;
};

#endif // !NUMERAL_NUMBER_HPP
