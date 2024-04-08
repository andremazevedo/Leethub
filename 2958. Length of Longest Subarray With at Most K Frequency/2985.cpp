#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLength = 0;
        unordered_map<int, int> hashmap;

        for (int i = 0, j = 0; j < nums.size(); j++) {
            hashmap[nums[j]]++;

            while (hashmap[nums[j]] > k) {
                hashmap[nums[i++]]--;
            }

            maxLength = max(maxLength, j - i + 1);
        }
        
        return maxLength;
    }
};

int main() {

    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;
    
    printInput(getName(nums), nums, getName(k), k);
    
    printOutput(Solution().maxSubarrayLength(nums, k));

    return 0;
}
