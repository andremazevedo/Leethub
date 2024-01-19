#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hashmap;
        unordered_set<int> hashset;

        for (int i = 0; i < arr.size(); i++)
            hashmap[arr[i]]++;

        for (auto i = hashmap.begin(); i != hashmap.end(); i++) {
            if(hashset.count(i->second) > 0)
                return false;
            hashset.insert(i->second);
        }

        return true;
    }
};

int main() {

    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    
    cout << "Input: arr = " << arr << endl;
    
    cout << "Output: " << Solution().uniqueOccurrences(arr) << endl;

    return 0;
}
