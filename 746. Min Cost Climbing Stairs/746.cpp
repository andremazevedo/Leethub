#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mininumCost(cost.size() + 1);

        mininumCost[0] = 0;
        mininumCost[1] = 0;
        for (size_t i = 2; i < cost.size() + 1; i++)
            mininumCost[i] = min(mininumCost[i - 2] + cost[i - 2], mininumCost[i - 1] + cost[i - 1]);

        return mininumCost[cost.size()];
        
    }
};

int main() {

    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    
    cout << "Input: cost = " << cost  << endl;
    
    cout << "output: " << Solution().minCostClimbingStairs(cost) << endl;

    return 0;
}