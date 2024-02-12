#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority;
        unordered_map<int, int> hashmap;

        for (int i : nums) {
            hashmap[i]++;

            if (hashmap[i] > nums.size() / 2 ) {
                majority = i;
                break;
            }
        }
        
        return majority;
    }
};

int main() {

    vector<int> nums = {3,2,3};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().majorityElement(nums) << endl;

    return 0;
}
