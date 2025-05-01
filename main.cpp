#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <unordered_map>

class RomanNumerals {
public:
    static std::string to_roman(unsigned int num) {
        static const std::array<std::string, 4> 
        thousands = {"", "M", "MM", "MMM"};

        static const std::array<std::string, 10> 
        hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

        static const std::array<std::string, 10> 
        tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

        static const std::array<std::string, 10> 
        ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        unsigned int th = num / 1000;
        unsigned int h = (num / 100) % 10;
        unsigned int te = (num / 10) % 10;
        unsigned int o = num % 10;

        return thousands[th] + hundreds[h] + tens[te] + ones[o];
    }

    static int from_roman(const std::string &s) {
        static const std::unordered_map<char,int> val = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };

        int total = 0;
        int prev = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            int curr = val.at(s[i]);
            if (curr < prev) total -= curr;
            else {
                total += curr;
                prev = curr;
            }
        }
        return total;
    }
};

void test_roman_numerals() {
    assert(RomanNumerals::to_roman(4)     == "IV");
    assert(RomanNumerals::to_roman(1)     == "I");
    assert(RomanNumerals::to_roman(9)     == "IX");
    assert(RomanNumerals::to_roman(58)    == "LVIII");
    assert(RomanNumerals::to_roman(1994)  == "MCMXCIV");
    assert(RomanNumerals::to_roman(2000)  == "MM");
    assert(RomanNumerals::to_roman(1666)  == "MDCLXVI");
    assert(RomanNumerals::to_roman(86)    == "LXXXVI");

    assert(RomanNumerals::from_roman("I")        == 1);
    assert(RomanNumerals::from_roman("IV")       == 4);
    assert(RomanNumerals::from_roman("IX")       == 9);
    assert(RomanNumerals::from_roman("LVIII")    == 58);
    assert(RomanNumerals::from_roman("MCMXCIV")  == 1994);
    assert(RomanNumerals::from_roman("MM")       == 2000);
    assert(RomanNumerals::from_roman("MDCLXVI") == 1666);
    assert(RomanNumerals::from_roman("LXXXVI")  == 86);

    std::cout << "All tests passed!\n";
}

int main() {
    test_roman_numerals();
    return 0;
}
