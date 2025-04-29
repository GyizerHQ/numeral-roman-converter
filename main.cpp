#include <iostream>
#include <cassert>


#include <string>

class RomanNumerals{
public:
    std::string to_roman(unsigned int n){
        return "";
    }
    int from_roman(std::string rn){
        return 0;
    }
};



void test_roman_numerals() {
    assert(RomanNumerals::to_roman(4) == "IV");
    assert(RomanNumerals::to_roman(1) == "I");
    assert(RomanNumerals::to_roman(4) == "IV");
    assert(RomanNumerals::to_roman(9) == "IX");
    assert(RomanNumerals::to_roman(58) == "LVIII");
    assert(RomanNumerals::to_roman(1994) == "MCMXCIV");


    assert(RomanNumerals::from_roman("I") == 1);
    assert(RomanNumerals::from_roman("IV") == 4);
    assert(RomanNumerals::from_roman("IX") == 9);
    assert(RomanNumerals::from_roman("LVIII") == 58);
    assert(RomanNumerals::from_roman("MCMXCIV") == 1994);
}

int main() {
    test_roman_numerals();
    return 0;
}