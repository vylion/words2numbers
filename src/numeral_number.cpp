
#include "numeral_number.hpp"

NumeralNumber::NumeralNumber(std::string word) : NumeralWord(word) {};

NumeralNumber::~NumeralNumber() {
    if (_power != nullptr) {
        delete _power;
    }
}

int NumeralNumber::evaluate() {
    if (_power != nullptr) {
        return _value * _power->evaluate();
    }

    return _value;
}