#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> left = {0};
        vector<int> right = {0};

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > x)
                break;
            left.push_back(sum);
        }

        sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            sum += nums[i];
            if (sum > x)
                break;
            right.push_back(sum);
        }

        int min = -1;
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                if (min != -1 && i + j >= min) 
                    break;

                if (i + j > nums.size()) 
                    break;

                if (left[i] + right[j] > x)
                    break;

                if (left[i] + right[j] == x)
                    min = i + j;
            }
        }

        return min;
    }
};

// class Solution {
// public:
//     int minOperations(vector<int>& nums, int x) {

//         int min = -1;
//         int rightSum = 0;
//         int l
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = nums.size() - 1; ; ++j) {
//                 if (min != -1 && i + j >= min) 
//                     break;

//                 if (left[i] + right[j] > x)
//                     break;

//                 if (left[i] + right[j] == x)
//                     min = i + j;
//             }
//         }

//         return min;
//     }
// };

int main() {

    // vector<int> nums = {1,1,4,2,3};
    // int x = 5;

    // vector<int> nums = {3,2,20,1,1,3};
    // int x = 10;

    vector<int> nums = {1,1};
    int x = 3;
    
    cout << "Input: nums = " << nums << ", x = " << x << endl;
    
    cout << "output: " << Solution().minOperations(nums, x) << endl;

    return 0;
}