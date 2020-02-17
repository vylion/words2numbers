#ifndef NUMERAL_MANAGER_HPP
#define NUMERAL_MANAGER_HPP

#include <string>
#include <unordered_map>
#include "trie.hpp"
#include "numeral_word.hpp"
#include "numeral_number.hpp"
#include "numeral_modifier.hpp"

class NumeralManager
{
public:
    bool isNumeralWord(std::string word);
    static NumeralManager &getInstance();
    NumeralWord *analyze(std::string &text);
    NumeralManager() : _numeral_exclusive(),
                       _context_dependent(),
                       _numeral_context(false),
                       _values(),
                       _modifiers(){};
    void language_setup();

private:
    bool add(std::string word, int value, bool exclusive);                    // numbers
    bool add(std::string word, NumeralModifier::Join joiner, bool exclusive); // modifiers
    NumeralWord *analyze_numeral(std::string &text, int &pos, bool &alnum_state, bool &is_alnum, int &val);

    // some words may be exclusively numeral ("one"), while others may
    // be context dependent ("and"), this is, they may appear outside
    // numerals
    Trie _numeral_exclusive;
    Trie _context_dependent;
    bool _numeral_context;
    std::unordered_map<std::string, int> _values;
    std::unordered_map<std::string, NumeralModifier::Join> _modifiers;
};

#endif // !NUMERAL_MANAGER_HPP