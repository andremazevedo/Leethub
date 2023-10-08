#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index = -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;

            if (nums[m] == target) {
                index = m;
                break;
            }

            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        vector<int> positions(2, index);

        while (positions[0] != -1 && 0 <= positions[0] - 1 && nums[positions[0] - 1] == target)
            positions[0] -= 1;

        while (positions[1] != -1 && positions[1] + 1 < nums.size() && nums[positions[1] + 1] == target)
            positions[1] += 1;

        return positions;
    }
};

int main() {

    vector<int> nums = {2,2};
    int target = 2;
    
    cout << "Input: nums = " << nums << ", target = " << target << endl;
    
    cout << "output: " << boolalpha << Solution().searchRange(nums, target) << endl;

    return 0;
}
