#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, -1);

        dp[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmp = dp;

            for (auto &flight : flights) {
                if (dp[flight[0]] != -1) {
                    if (tmp[flight[1]] == -1 || dp[flight[0]] + flight[2] < tmp[flight[1]]) {
                        tmp[flight[1]] = dp[flight[0]] + flight[2];
                    }
                }
            }

            dp = tmp;
        }

        return dp[dst];
    }
};

int main() {

    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    
    cout << "Input: n = " << n << ", flights = " << flights << ", src = " << src << ", dst = " << dst << ", k = " << k << endl;
    
    cout << "Output: " << Solution().findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}
