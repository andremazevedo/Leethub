#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int pos, n;

        for (int j = 0; j < dp.size(); j++) {
            for (int i = 0; i < dp.size() - j; i++) {
                if (s[i] == s[i + j] && (j < 2 || dp[i + 1][i + j - 1])) {
                    dp[i][i + j] = true;
                    pos = i;
                    n = j + 1;
                }
            }
        }
        
        return s.substr(pos, n);
    }
};

int main() {

    string s = "babad";
    
    cout << "Input: s = \"" << s << "\"" << endl;
    
    cout << "Output: \"" << Solution().longestPalindrome(s) << "\"" << endl;

    return 0;
}
