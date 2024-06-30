#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j + i < s.length(); j++) {
                if (i == 0 || (s[j] == s[j + i] && (i == 1 || dp[j + 1][j + i - 1]))) {
                    dp[j][j + i] = true;
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {

    string s = "";
    
    cout << "Input: s = " << s << endl;
    
    cout << "Output: " << Solution().countSubstrings(s) << endl;

    return 0;
}
