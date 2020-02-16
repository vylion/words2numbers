
#ifndef NUMERAL_MODIFIER_HPP
#define NUMERAL_MODIFIER_HPP

#include "numeral_word.hpp"

class NumeralModifier : public virtual NumeralWord {
    public:
    enum Join {ADD, SUBSTRACT};

    NumeralModifier(std::string word, Join joiner);
    int evaluate();

    private:
    Join _joiner;
    NumeralWord *_left, *_right;

    int evaluate(NumeralWord* child);
};

#endif // !NUMERAL_MODIFIER_HPP
