#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;

        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.count(target - nums[i]) > 0)
                return {hashmap[target - nums[i]], i};
            hashmap[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    vector<int> nums = {2,7,11,15};
    int target = 9;
    
    cout << "Input: nums = " << nums << ", target = " << target << endl;
    
    cout << "Output: " << Solution().twoSum(nums, target) << endl;

    return 0;
}
