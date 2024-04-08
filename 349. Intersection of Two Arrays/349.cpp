#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_set<int> hashset1;
        unordered_set<int> hashset2;

        for (int i : nums1)
            hashset1.insert(i);
        
        for (auto i : nums2) {
            if (hashset2.count(i) == 0) {
                hashset2.insert(i);

                if (hashset1.count(i) > 0)
                    answer.push_back(i);
            }
        }
        
        return answer;
    }
};

int main() {

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    
    cout << "Input: nums1 = " << nums1 << ", nums2 = " << nums2 << endl;
    
    cout << "Output: "<< Solution().intersection(nums1, nums2) << endl;

    return 0;
}
