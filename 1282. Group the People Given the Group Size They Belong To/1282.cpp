#include <iostream>
#include <vector>
#include <unordered_map>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        unordered_map<int, vector<int>> groupSizesMap;

        for (int i = 0; i < groupSizes.size(); ++i) {
            groupSizesMap[groupSizes[i]].push_back(i);

            if (groupSizesMap[groupSizes[i]].size() == groupSizes[i]) {
                groups.push_back(groupSizesMap[groupSizes[i]]);
                groupSizesMap[groupSizes[i]].clear();
            }
        }

        return groups;
    }
};

int main() {

    // vector<int> groupSizes = {3,3,3,3,3,1,3};
    vector<int> groupSizes = {2,1,3,3,3,2};
    
    cout << "Input: groupSizes = " << groupSizes << endl;
    
    cout << "output: " << Solution().groupThePeople(groupSizes) << endl;

    return 0;
}
