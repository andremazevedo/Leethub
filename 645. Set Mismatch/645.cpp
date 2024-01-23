#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int twice, missing = 1;
        unordered_set<int> hashset;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == missing) {
                missing += 1;
            }
            
            if (hashset.count(nums[i]) > 0) {
                twice = nums[i];
            }
            
            hashset.insert(nums[i]);
        }
        
        return {twice, missing};        
    }
};

int main() {

    vector<int> nums = {1,5,3,2,2,7,6,4,8,9};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().findErrorNums(nums) << endl;

    return 0;
}
