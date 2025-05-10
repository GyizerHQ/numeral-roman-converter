#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

class RomanNumerals {
public:
    std::string to_roman(unsigned int n) {
        std::string ones[]  = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        std::string tens[]  = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        std::string hrns[]  = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        std::string ths[]   = {"","M","MM","MMM"};

        return ths[n/1000] + hrns[(n%1000)/100] + tens[(n%100)/10] + ones[n%10];
    }

    int from_roman(const std::string& rn) {
        int ans = 0;
        std::unordered_map<char, int> mp = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };

        for (size_t i = 0; i < rn.size(); ++i) {
            if (i + 1 < rn.size() && mp[rn[i]] < mp[rn[i + 1]]) {
                ans -= mp[rn[i]];
            } else {
                ans += mp[rn[i]];
            }
        }
        return ans;
    }
};

void test_roman_numerals() {
    RomanNumerals rn;

    assert(rn.to_roman(1) == "I");
    assert(rn.to_roman(4) == "IV");
    assert(rn.to_roman(9) == "IX");
    assert(rn.to_roman(58) == "LVIII");
    assert(rn.to_roman(1994) == "MCMXCIV");

    assert(rn.from_roman("I") == 1);
    assert(rn.from_roman("IV") == 4);
    assert(rn.from_roman("IX") == 9);
    assert(rn.from_roman("LVIII") == 58);
    assert(rn.from_roman("MCMXCIV") == 1994);
}

int main() {
    test_roman_numerals();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}