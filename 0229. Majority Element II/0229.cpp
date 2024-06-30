#include "../streamUtils.hpp"
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        vector<int> vec;

        for (size_t i = 0; i < nums.size(); i++)
                hashmap[nums[i]]++;

        for (auto iter = hashmap.begin(); iter != hashmap.end(); ++iter)
            if (iter->second > nums.size() / 3)
                vec.push_back(iter->first);

        return vec;
    }
};

int main() {

    vector<int> nums = {1};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "output: " << Solution().majorityElement(nums) << endl;

    return 0;
}
