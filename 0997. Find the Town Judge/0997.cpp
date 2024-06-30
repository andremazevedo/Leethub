#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> hashmap;
        unordered_set<int> hashset;

        for (int i = 1; i <= n; i++)
            hashset.insert(i);

        for (auto i : trust) {
            hashmap[i[1]]++;

            if (hashset.count(i[0]) > 0)
                hashset.erase(i[0]);
        }

        for (auto i : hashset) {
            if (hashmap[i] == n - 1)
                return i;
        }

        return -1;
    }
};

int main() {

    int n = 2;
    vector<vector<int>> trust = {{1,2}};
    
    cout << "Input: n = " << n << ", trust = " << trust << endl;
    
    cout << "Output: " << Solution().findJudge(n, trust) << endl;

    return 0;
}
