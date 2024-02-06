#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k)
                return {};
            
            answer.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        
        return answer;
    }
};

int main() {

    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 4;
    
    cout << "Input: nums = " << nums << ", k = " << k << endl;
    
    cout << "Output: "<< Solution().divideArray(nums, k) << endl;

    return 0;
}
