#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int min = 0;

        if (nums.size() < 5)
            return min;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < 4; i++) {
            int diff = nums[nums.size() - 4 + i] - nums[i];
            if (diff < min || min == 0)
                min = diff;
        }

        return min;
    }
};

int main() {

    vector<int> nums = {6,6,0,1,1,4,6};
    
    printInput(getName(nums), nums);

    printOutput(Solution().minDifference(nums));

    return 0;
}
