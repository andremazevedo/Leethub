#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n, 1);

        for (size_t i = 2; i < n; i++) {
            for (size_t j = 0; j < i; j++) {
                int k = dp[i - (j + 1)] > i - j ? dp[i - (j + 1)] : i - j;
                if ((j + 1) * k > dp[i])
                    dp[i] =  (j + 1) * k;
            }  
        }
        
        return dp[n - 1];
    }
};

int main() {

    int n = 10;
    
    cout << "Input: n = " << n << endl;
    
    cout << "Output: " << Solution().integerBreak(n) << endl;

    return 0;
}
