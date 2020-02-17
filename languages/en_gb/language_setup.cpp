#include "numeral_manager.hpp"
#include <iostream>

void NumeralManager::language_setup()
{
    add("one", 1, true);
    add("two", 2, true);
    add("three", 3, true);
    add("four", 4, true);
    add("five", 5, true);
    add("six", 6, true);
    add("seven", 7, true);
    add("eight", 8, true);
    add("nine", 9, true);

    add("ten", 10, true);
    add("twenty", 20, true);
    add("thirty", 30, true);
    add("fourty", 40, true);
    add("forty", 40, true);
    add("fifty", 50, true);
    add("sixty", 60, true);
    add("seventy", 70, true);
    add("eighty", 80, true);
    add("ninety", 90, true);

    add("hundred", 100, true);

    add("thousand", 1000, true);

    add("and", NumeralModifier::ADD, false);
}