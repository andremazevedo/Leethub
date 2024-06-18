#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int length = 0;
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        for (auto &p : freq) {
            if (length % 2 == 0)
                length += p.second;
            else
                length += p.second % 2 == 0 ? p.second : p.second - 1;
        }

        return length;
    }
};

int main() {

    string s = "bananas";

    printInput(getName(s), s);
    
    printOutput(Solution().longestPalindrome(s));

    return 0;
}
