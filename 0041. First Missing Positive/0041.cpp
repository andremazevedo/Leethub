#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = 1;
        unordered_set<int> hashmap;

        for (auto i : nums) {
            if (i == n)
                while (hashmap.count(++n) > 0);

            hashmap.insert(i);
        }
        
        return n;
    }
};

int main() {

    int n = 4;
    vector<int> nums = {1,2,0};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: "<< Solution().firstMissingPositive(nums) << endl;

    return 0;
}
