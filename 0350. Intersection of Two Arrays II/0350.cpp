#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_map<int, int> hashmap;

        for (int i : nums1)
            hashmap[i]++;

        for (auto i : nums2) {
            if (hashmap[i] > 0)
                answer.push_back(i);
            hashmap[i]--;
        }

        return answer;
    }
};

int main() {

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    
    printInput(getName(nums1), nums1, getName(nums2), nums2);

    printOutput(Solution().intersect(nums1, nums2));

    return 0;
}
