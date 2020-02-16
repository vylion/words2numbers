
#ifndef NUMERAL_WORD_HPP
#define NUMERAL_WORD_HPP

#include <string>

class NumeralWord {
    public:
    NumeralWord(std::string word) : _word(word) {};
    virtual ~NumeralWord();
    virtual int evaluate();

    protected:
    std::string _word;
};

#endif // !NUMERAL_WORD_HPP