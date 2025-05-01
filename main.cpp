#include <iostream>
#include <cassert>
#include <string>
#include <vector>

class RomanNumerals {
public:
    static std::string to_roman(unsigned int n) {
        std::vector<std::pair<int, std::string>> symbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"}, {1, "I"}
        };

        std::string result;
        for (const auto& [value, symbol] : symbols) {
            while (n >= value) {
                result += symbol;
                n -= value;
            }
        }
        return result;
    }

    static int from_roman(std::string rn) {
        std::vector<std::pair<std::string, int>> symbols = {
            {"CM", 900}, {"CD", 400}, {"XC", 90}, {"XL", 40},
            {"IX", 9},   {"IV", 4},   {"M", 1000}, {"D", 500},
            {"C", 100},  {"L", 50},   {"X", 10},   {"V", 5}, {"I", 1}
        };

        int total = 0;
        size_t i = 0;
        while (i < rn.size()) {
            bool matched = false;
            for (const auto& [symbol, value] : symbols) {
                if (rn.substr(i, symbol.size()) == symbol) {
                    total += value;
                    i += symbol.size();
                    matched = true;
                    break;
                }
            }
            if (!matched) ++i; 
        }
        return total;
    }
};

void test_roman_numerals() {
    assert(RomanNumerals::to_roman(4) == "IV");
    assert(RomanNumerals::to_roman(1) == "I");
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
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
