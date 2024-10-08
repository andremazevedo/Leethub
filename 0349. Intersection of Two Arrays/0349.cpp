#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_set<int> hashset;

        for (int i : nums1)
            hashset.insert(i);

        for (auto i : nums2) {
            if (hashset.count(i) > 0)
                answer.push_back(i);
            hashset.erase(i);
        }
        
        return answer;
    }
};

int main() {

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2,3};
    
    printInput(getName(nums1), nums1, getName(nums2), nums2);
    
    printOutput(Solution().intersection(nums1, nums2));

    return 0;
}
