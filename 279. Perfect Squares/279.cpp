#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int num = i;

            for (int j = 1; pow(j, 2) <= i; j++)
                num = min(num, dp[i - pow(j, 2)] + 1);
            
            dp[i] = num;
        }
        
        
        return dp[n];
    }
};

int main() {

    int n = 43;
    
    cout << "Input: n = " << n << endl;
    
    cout << "Output: " << Solution().numSquares(n) << endl;

    return 0;
}
