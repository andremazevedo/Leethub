#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto num : nums) {
            if (hashset.count(num))
                hashset.erase(num);
            else
                hashset.insert(num);
        }
        return *hashset.begin();
    }
};

int main() {

    vector<int> nums = {4,1,2,1,2};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().singleNumber(nums) << endl;

    return 0;
}
