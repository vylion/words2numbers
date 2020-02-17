#include "numeral_modifier.hpp"

NumeralModifier::~NumeralModifier()
{
    if (_left != nullptr)
    {
        delete _left;
    }

    if (_right != nullptr)
    {
        delete _right;
    }
}

void NumeralModifier::setChild(NumeralWord *child)
{
    if (_right != nullptr)
    {
        _right->setChild(child);
    }
    else
    {
        _right = child;
    }
}

int NumeralModifier::evaluate(NumeralWord *child)
{
    if (child == nullptr)
    {
        return 0;
    }

    return child->evaluate();
}

int NumeralModifier::evaluate()
{
    switch (_joiner)
    {
    case ADD:
        return evaluate(_left) + evaluate(_right);
        //break;

    case SUBSTRACT:
        return evaluate(_left) - evaluate(_right);
        //break;

    default:
        return 0;
        //break;
    }
}

std::string NumeralModifier::to_string()
{
    std::string out = _repr + "(";
    if (_left != nullptr)
    {
        out += _left->to_string();
    }
    else
    {
        out += "null";
    }
    out += std::string(",");
    if (_right != nullptr)
    {
        out += _right->to_string();
    }
    else
    {
        out += "null";
    }
    out += std::string(")");
    return out;
}
