
#include "numeral_number.hpp"

NumeralNumber::~NumeralNumber()
{
    if (_power != nullptr)
    {
        delete _power;
    }
}

void NumeralNumber::setChild(NumeralWord *child)
{
    if (_power != nullptr)
    {
        _power->setChild(child);
    }
    else
    {
        _power = child;
    }
}

int NumeralNumber::evaluate()
{
    if (_power != nullptr)
    {
        return _value * _power->evaluate();
    }

    return _value;
}

std::string NumeralNumber::to_string()
{
    std::string out = _repr + "*";
    if (_power != nullptr)
    {
        out += _power->to_string();
    }
    else
    {
        out += "null";
    }
    return out;
}