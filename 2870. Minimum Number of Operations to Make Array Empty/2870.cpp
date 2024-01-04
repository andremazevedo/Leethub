#include "../streamUtils.hpp"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int min = 0;
        unordered_map<int,int> hashmap;

        for (int num : nums)
            hashmap[num]++;
    
        for (auto i : hashmap) {
            if (i.second <= 1)
                return -1;
    
            int deleteThree = i.second / 3;

            while ((i.second - 3 * deleteThree) % 2 != 0) {
                deleteThree--;
            }
            
            min += deleteThree + (i.second - 3 * deleteThree) / 2;
        }

        return min;
    }
};

int main() {

    vector<int> nums = {2,3,3,2,2,4,2,3,4};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().minOperations(nums) << endl;

    return 0;
}
