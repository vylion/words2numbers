
#include "numeral_modifier.hpp"

NumeralModifier::NumeralModifier(std::string word, Join joiner) : NumeralWord(word), _joiner(joiner) {};

NumeralModifier::~NumeralModifier() {
    if (_left != nullptr) {
        delete _left;
    }

    if (_right != nullptr) {
        delete _right;
    }
}

int NumeralModifier::evaluate(NumeralWord* child) {
    if (child == nullptr) {
        return 0;
    }
    
    return child->evaluate();
}

int NumeralModifier::evaluate() {
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

