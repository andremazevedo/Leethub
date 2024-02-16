#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;  
    }

public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words)
            if (isPalindrome(s))
                return s;
        return "";
    }
};

int main() {

    vector<string> words = {"abc","car","ada","racecar","cool"};
    
    cout << "Input: nums = " << words << endl;
    
    cout << "Output: " << Solution().firstPalindrome(words) << endl;

    return 0;
}
