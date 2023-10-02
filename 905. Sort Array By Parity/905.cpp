#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); j++)
            if (nums[j] % 2 == 0)
                swap(nums[i++], nums[j]);
        return nums;
    }
};

int main() {

    vector<int> nums = {3,1,2,4};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "output: " << Solution().sortArrayByParity(nums) << endl;

    return 0;
}
