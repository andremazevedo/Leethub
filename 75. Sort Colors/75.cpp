#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        for (int color = 0; color < 3; color++)
            for (int j = 0; j < nums.size(); j++)
                if (nums[j] == color)
                    swap(nums[i++], nums[j]);
    }
};

int main() {

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    printInput(getName(nums), nums);

    Solution().sortColors(nums);

    printOutput(nums);

    return 0;
}
