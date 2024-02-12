#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> answer = {};
        vector<vector<int>> dp(nums.size());

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            vector<int> divisible;

            for (int j = 0; j < i; j++)
                if (nums[i] % nums[j] == 0 && divisible.size() < dp[j].size())
                    divisible = dp[j];

            divisible.push_back(nums[i]);
            dp[i] = divisible;

            if (answer.size() < divisible.size())
                answer = divisible;
        }
        
        return answer;
    }
};

int main() {

    vector<int> nums = {1,2,3};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().largestDivisibleSubset(nums) << endl;

    return 0;
}
