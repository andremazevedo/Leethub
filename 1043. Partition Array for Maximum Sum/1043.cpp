#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            int maxSum, partitionSum, maxVal = 0;

            for (int j = 0; j < k && i - j >= 0; j++) {
                maxVal = max(maxVal, arr[i - j]);

                if (i - j - 1 >= 0)
                    partitionSum = dp[i - j - 1] + maxVal * (j + 1);
                else
                    partitionSum = maxVal * (j + 1);

                maxSum = max(maxSum, partitionSum);
            }
            
            dp[i] = maxSum;
        }
        
        return dp[arr.size() - 1];
    }
};

int main() {

    vector<int> arr = {1};
    int k = 1;
    
    cout << "Input: arr = " << arr << ", k = " << k << endl;
    
    cout << "Output: "<< Solution().maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}
