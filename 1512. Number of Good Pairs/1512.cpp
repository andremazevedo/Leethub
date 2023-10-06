#include "../streamUtils.hpp"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = 0;
        unordered_map<int,int> countingMap;
        
        for (auto& i : nums) {
            if (countingMap[i])
                countingMap[i]++;
            else
                countingMap[i] = 1;
        }

        for (auto& pair : countingMap) 
            for (int i = pair.second - 1; i > 0; i--)
                n += i;
        
        return n;
    }
};

int main() {

    vector<int> nums = {1,2,3,1,1,3};
    
    cout << "Input: nums = " << nums << endl;
    
    cout << "output: " << Solution().numIdenticalPairs(nums) << endl;

    return 0;
}
