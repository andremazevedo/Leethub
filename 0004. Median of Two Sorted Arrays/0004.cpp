#include <iostream>
#include <vector>
#include <unordered_map>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double i = 0, j = 0;
        double n1, n2;

        while (i + j < (int)((nums1.size() + nums2.size()) / 2) - 1) {
            if (j >= nums2.size() || (i < nums1.size() && nums1[i] < nums2[j]))
                i++;
            else
                j++;
        }

        if (nums1.size() + nums2.size() > 1) {
            if (j >= nums2.size() || (i < nums1.size() && nums1[i] < nums2[j]))
                n1 = nums1[i++];
            else 
                n1 = nums2[j++];
        }

        if (j >= nums2.size() || (i < nums1.size() && nums1[i] < nums2[j]))
            n2 = nums1[i];
        else 
            n2 = nums2[j];

        if ((nums1.size() + nums2.size()) % 2 == 0)
            return (n1 + n2) / 2;
        else
            return n2;
    }
};

int main() {

    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    
    cout << "Input: nums1 = " << nums1 << ", nums2 = " << nums2 << endl;
    
    cout << "output: " << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}