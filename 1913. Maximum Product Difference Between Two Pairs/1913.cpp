#include "../streamUtils.hpp"
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
    }
};

int main() {

    vector<int> nums = {5,6,2,7,4};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().maxProductDifference(nums) << endl;

    return 0;
}