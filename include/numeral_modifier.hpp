#ifndef NUMERAL_MODIFIER_HPP
#define NUMERAL_MODIFIER_HPP

#include "numeral_word.hpp"

class NumeralModifier : public virtual NumeralWord
{
public:
    enum Join
    {
        ADD,
        SUBSTRACT
    };

    NumeralModifier(std::string repr, NumeralWord *left, Join joiner) : NumeralWord(repr), _left(left), _right(nullptr), _joiner(joiner){};
    NumeralModifier(std::string repr, Join joiner) : NumeralModifier(repr, nullptr, joiner){};
    ~NumeralModifier();
    void setChild(NumeralWord *child);
    int evaluate();
    std::string to_string();

private:
    NumeralWord *_left, *_right;
    Join _joiner;

    int evaluate(NumeralWord *child);
};

#endif // !NUMERAL_MODIFIER_HPP
