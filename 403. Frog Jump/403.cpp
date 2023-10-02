#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& vec)
{
    os << "[";
    for (const auto& element : vec) {
        if (element == vec.back())
            os << element;
        else
            os << element << ",";
    }
    os << "]";
    return os;
}

class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size());

        dp[0] = {0};
        for (int i = 0; i < stones.size(); i++) {

            for (int k : dp[i]) {

                int j = i + 1;
                while (j < stones.size() && stones[j] <= (stones[i] + k + 1)) {
                    for (int jump : {k - 1, k, k + 1}) {
                        if (stones[i] + jump == stones[j]) {
                            if (j == stones.size() - 1) {
                                return true;
                            }

                            if (!count(dp[j].begin(), dp[j].end(), jump)) {
                                dp[j].push_back(jump);
                            }
                        }     
                    }
                    j++;
                }
                
            }
        }
        
        return false;
    }
};

int main() {

    vector<int> stones = {0,1,3,5,6,8,12,17};
    
    cout << "Input: stones = " << stones << endl;
    
    cout << "output:" << Solution().canCross(stones) << endl;

    return 0;

}
