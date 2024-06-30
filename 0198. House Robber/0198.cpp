#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];

        if (nums.size() > 1)
            dp[1] = max(dp[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        
        return dp[nums.size() - 1];
    }
};

int main() {

    vector<int> nums = {1,2,3,1};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().rob(nums) << endl;

    return 0;
}
