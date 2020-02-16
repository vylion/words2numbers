
#ifndef NUMERAL_INDEX_HPP
#define NUMERAL_INDEX_HPP

#include <string>
#include <unordered_map>

class NumeralIndex {
    public:
    bool add(std::string word, int value);

    private:
    std::unordered_map<std::string, int> index();
};

#endif // !NUMERAL_INDEX_HPP