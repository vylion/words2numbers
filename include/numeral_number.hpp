
#ifndef NUMERAL_NUMBER_HPP
#define NUMERAL_NUMBER_HPP

#include "numeral_word.hpp"

class NumeralNumber : public virtual NumeralWord {
    public:
    NumeralNumber(std::string word);
    int evaluate();

    private:
    int _value;
    NumeralNumber* _power;
};

#endif // !NUMERAL_NUMBER_HPP
