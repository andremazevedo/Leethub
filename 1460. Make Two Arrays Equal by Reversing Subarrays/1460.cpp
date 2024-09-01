#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < target.size(); i++) {
            hashmap[target[i]]++;
            hashmap[arr[i]]--;
        }

        for (auto& [key, value] : hashmap) {
            if (value != 0)
                return false;
        }

        return true;
    }
};

int main() {

    vector<int> target = {1,2,3,4};
    vector<int> arr = {2,4,1,3};
    
    printInput(getName(target), target, getName(arr), arr);
    
    printOutput(Solution().canBeEqual(target, arr));

    return 0;
}
