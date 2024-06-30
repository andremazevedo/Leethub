#include <iostream>
#include <vector>
#include <unordered_map>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<string> combinations = {};

    unordered_map<char, string> digitsMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    vector<string> letterCombinations(string digits) {

        if (!digits.empty()) {
            for (char c : digitsMap[digits[0]]) {
                letterCombinations2(string(1, c), digits.substr(1, digits.size() - 1));
            }
        }

        return combinations;
    }

    void letterCombinations2(string letter, string digits) {

        if (digits.empty()) {
            combinations.push_back(letter);
            return;
        }

        for (char c : digitsMap[digits[0]]) {
            letterCombinations2(letter + c, digits.substr(1, digits.size() - 1));
        }
    }
};

int main() {

    string digits = "23";
    // string digits = "";
    
    cout << "Input: digits = \"" << digits << "\"" << endl;
    
    cout << "output: " << Solution().letterCombinations(digits) << endl;

    return 0;
}