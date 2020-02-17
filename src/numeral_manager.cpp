#include <iostream>
#include "numeral_manager.hpp"

bool NumeralManager::add(std::string word, int value, bool exclusive)
{
    bool success = false;
    if (exclusive)
    {
        success = _numeral_exclusive.insert(word);
    }
    else
    {
        success = _context_dependent.insert(word);
    }

    _values[word] = value;
    return success;
}

bool NumeralManager::add(std::string word, NumeralModifier::Join joiner, bool exclusive)
{
    bool success = false;
    if (exclusive)
    {
        success = _numeral_exclusive.insert(word);
    }
    else
    {
        success = _context_dependent.insert(word);
    }

    _modifiers[word] = joiner;
    return success;
}

bool NumeralManager::isNumeralWord(std::string word)
{
    bool exclusive_find = _numeral_exclusive.search(word);

    return exclusive_find || (_numeral_context && _context_dependent.search(word));
}

NumeralWord *NumeralManager::analyze_numeral(std::string &text, int &pos, bool &alnum_state, bool &is_alnum, int &last_val)
{
    std::string word = "";
    NumeralWord *numeral = nullptr;
    int val = last_val;
    int old_pos = pos;
    alnum_state = std::isalnum(text[pos]);
    is_alnum = std::isalnum(text[pos]);

    while (pos < text.length())
    {
        word = "";

        while (pos < text.length() && is_alnum == alnum_state)
        {
            word += text[pos];
            pos++;
            is_alnum = std::isalnum(text[pos]);
        }

        if (alnum_state == true && !word.empty())
        {
            // If we have read an alphanumeric chunk of characters
            if (_modifiers.find(word) != _modifiers.end())
            {
                if (numeral == nullptr)
                {
                    numeral = new NumeralModifier(word, _modifiers[word]);
                }
                else
                {
                    NumeralModifier *mod = new NumeralModifier(word, numeral, _modifiers[word]);
                    NumeralWord *next_numeral = analyze_numeral(text, pos, alnum_state, is_alnum, val);
                    mod->setChild(next_numeral);

                    numeral = mod;
                }
            }
            else if (_values.find(word) != _values.end())
            {
                val = _values[word];

                if (numeral == nullptr)
                {
                    numeral = new NumeralNumber(word, val);
                }
                else if (val >= last_val)
                {
                    // Assumes eurocentric property where bigger values
                    // following smaller values is a multiplication
                    // (like in "two hundred")
                    NumeralNumber *num = new NumeralNumber(word, val);
                    numeral->setChild(num);
                }
                else
                {
                    // Assumes eurocentric property where smaller values
                    // following bigger values is a sum (like in "forty two")
                    NumeralModifier *mod = new NumeralModifier("+", numeral, NumeralModifier::ADD);

                    NumeralWord *next_numeral = analyze_numeral(text, old_pos, alnum_state, is_alnum, val);
                    pos = old_pos;
                    mod->setChild(next_numeral);

                    numeral = mod;
                }

                last_val = val;
            }
        }

        old_pos = pos;

        alnum_state = std::isalnum(text[pos]);
    }

    return numeral;
}

NumeralWord *NumeralManager::analyze(std::string &text)
{ // We assume that this is called on a text that we already know is entirely a numeral
    std::string word = "";
    int pos = 0;
    bool alnum_state = std::isalnum(text[pos]);
    bool is_alnum = std::isalnum(text[pos]);
    int last_val = 0;

    return analyze_numeral(text, pos, alnum_state, is_alnum, last_val);
}