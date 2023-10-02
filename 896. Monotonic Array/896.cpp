#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIcreasing = false, isDecreasing = false;

        for (int i = 1; i < nums.size(); ++i) {
            isIcreasing |= nums[i - 1] < nums[i];
            isDecreasing |= nums[i - 1] > nums[i];

            if (isIcreasing && isDecreasing)
                return false;
        }
    
        return true;
    }
};

int main() {

    vector<int> nums = {1,2,2,3};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "output: " << Solution().isMonotonic(nums) << endl;

    return 0;
}
