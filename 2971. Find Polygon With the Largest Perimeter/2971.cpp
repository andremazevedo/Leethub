#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long> prefixSum(nums.size());

        sort(nums.begin(), nums.end());

        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        
        for (int i = nums.size() - 1; i >= 2; i--)
            if (prefixSum[i - 1] > nums[i])
                return prefixSum[i];
        
        return -1;
    }
};

int main() {

    vector<int> nums = {1,12,1,2,5,50,3};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().largestPerimeter(nums) << endl;

    return 0;
}
