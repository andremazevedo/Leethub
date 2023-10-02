#include <iostream>
#include <stack>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        for (size_t i = 0, j = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            } else if (i == s.size() - 1) {
                reverse(s.begin() + j, s.end());
            }
        }
        return s;
    }
};

int main() {

    string s = "Let's take LeetCode contest";
    
    cout << "Input: s = \"" << s << "\"" << endl;
    
    cout << "output: \"" << Solution().reverseWords(s) << "\"" << endl;

    return 0;
}