#include "../streamUtils.hpp"
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sol;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (sol.empty())
                    sol.push_back(nums1[i]);
                else if (sol[sol.size() - 1] != nums1[i])
                    sol.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        return sol;
    }
};

int main() {

    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    
    cout << "Input: nums1 = " << nums1 << ", nums2 = " << nums2 << endl;
    
    cout << "output: " << Solution().intersection(nums1, nums2) << endl;

    return 0;
}