#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int unique = 0;
        unordered_map<int, int> hashmap;
        vector<int> frequencies;

        for (int i : arr) 
            hashmap[i]++;

        for (auto i : hashmap)
            frequencies.push_back(i.second);

        sort(frequencies.begin(), frequencies.end());

        for (int i = 0; i < frequencies.size(); i++)
            if (frequencies[i] <= k)
                k -= frequencies[i];
            else
                unique++;

        return unique;
    }
};


int main() {

    vector<int> arr = {4,3,1,1,3,3,2};
    int k = 3;
    
    cout << "Input: arr = " << arr << ", k = " << k << endl;
    
    cout << "Output: "<< Solution().findLeastNumOfUniqueInts(arr, k) << endl;

    return 0;
}