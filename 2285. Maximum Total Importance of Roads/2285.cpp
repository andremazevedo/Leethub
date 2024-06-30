#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long maxImportance = 0;
        vector<long> degree(n, 0);

        for (auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        sort(degree.begin(), degree.end());

        for (int i = 0; i < n; i++)
            maxImportance += degree[i] * (i + 1);

        return maxImportance;
    }
};

int main() {

    int n = 5;
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};

    printInput(getName(n), n, getName(roads), roads);
    
    printOutput(Solution().maximumImportance(n, roads));

    return 0;
}
