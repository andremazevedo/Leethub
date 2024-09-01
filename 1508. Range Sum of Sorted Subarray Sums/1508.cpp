#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long answer = 0;
        vector<int> sums;

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end());

        for (int i = left - 1; i < right; ++i) {
            answer += sums[i];
        }

        return answer % (int)(1e9 + 7);
    }
};

int main() {

    vector<int> nums = {1,2,3,4};
    int n = 4;
    int left = 1;
    int right = 5;
    
    printInput(getName(nums), nums, getName(n), n, getName(left), left, getName(right), right);
    
    printOutput(Solution().rangeSum(nums, n, left, right));

    return 0;
}
