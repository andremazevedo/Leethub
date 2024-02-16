#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer(nums.size());
        int pos = 0, neg = 1;

        for (int num : nums) {
            if (num > 0) {
                answer[pos] = num;
                pos += 2;
            }
            else {
                answer[neg] = num;
                neg += 2;
            }
        }

        return answer;
    }
};

int main() {

    vector<int> nums = {3,1,-2,-5,2,-4};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "Output: " << Solution().rearrangeArray(nums) << endl;

    return 0;
}
