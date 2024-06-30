#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> hashset;

        for (int num : nums)
            hashset.insert(num);

        for (int i = 0; i < nums.size(); i++)
            if (hashset.count(i) == 0)
                return i;

        return nums.size();
    }
};

int main() {

    vector<int> nums = {3,0,1};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().missingNumber(nums) << endl;

    return 0;
}
