#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> matrix;

        do {
            vector<int> distinct;
            vector<int> duplicate;
            unordered_set<int> hashset;
            for (int num : nums) {
                if (hashset.count(num) > 0) {
                    duplicate.push_back(num);
                    continue;
                }
                distinct.push_back(num);
                hashset.insert(num);
            }
            matrix.push_back(distinct);
            nums = duplicate;
        } while (nums.size());

        return matrix;
    }
};

int main() {

    vector<int> nums = {1,3,4,1,2,3,1};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().findMatrix(nums) << endl;

    return 0;
}
