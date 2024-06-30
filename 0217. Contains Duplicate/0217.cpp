#include "../streamUtils.hpp"
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int num : nums) {
            if (hashset.count(num) > 0)
                return true;
            hashset.insert(num);
        }
        return false;
    }
};

int main() {

    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "output: " << boolalpha << Solution().containsDuplicate(nums) << endl;

    return 0;
}