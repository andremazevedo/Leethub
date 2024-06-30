#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> degree(edges.size() + 2, 0);

        for (auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        int i = 1;
        while (i < degree.size() + 2 && degree[i] != edges.size()) i++;

        return i;
    }
};

int main() {

    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};

    printInput(getName(edges), edges);
    
    printOutput(Solution().findCenter(edges));

    return 0;
}
