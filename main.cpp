#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class RomanNumerals {
public:
    // Number to Roman numeral
    static string to_roman(unsigned int num) {
        string romansymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        
        // Loop through each Roman numeral
        for (int i = 0; i < 13; i++) {
            while (num >= value[i]) {
                ans += romansymbols[i];
                num -= value[i];
            }
        }
        return ans;
    }

    // Roman numeral to Number
    static int from_roman(string s) {
        int num1;
        if (s[s.length() - 1] == 'I') num1 = 1;
        if (s[s.length() - 1] == 'V') num1 = 5;
        if (s[s.length() - 1] == 'X') num1 = 10;
        if (s[s.length() - 1] == 'L') num1 = 50;
        if (s[s.length() - 1] == 'C') num1 = 100;
        if (s[s.length() - 1] == 'D') num1 = 500;
        if (s[s.length() - 1] == 'M') num1 = 1000;

        int ans = num1;
        bool flag = false;
        int number;

        // Loop through the Roman numeral string
        for (int i = s.length() - 2; i >= 0; i--) {
            int a = number;
            if (s[i] == 'I') number = 1;
            if (s[i] == 'V') number = 5;
            if (s[i] == 'X') number = 10;
            if (s[i] == 'L') number = 50;
            if (s[i] == 'C') number = 100;
            if (s[i] == 'D') number = 500;
            if (s[i] == 'M') number = 1000;

            // Logic to handle subtraction in Roman numerals
            if (flag == true) {
                if (number < a) {
                    ans -= number;
                } else if (number >= a) {
                    ans += number;
                }
            } else {
                if (number < ans) {
                    ans -= number;
                    flag = true;
                } else if (number >= ans) {
                    ans += number;
                    flag = true;
                }
            }
        }
        return ans;
    }
};

// Testing function
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
    cout << "All test cases passed" << endl;
    return 0;
}
