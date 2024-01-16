#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> hashmap;
        vector<vector<int>> answer(2);

        for (int i = 0; i < matches.size(); i++) {
            if (hashmap.count(matches[i][0]) == 0)
                hashmap[matches[i][0]] = 0;
            hashmap[matches[i][1]]++;
        }

        for (auto i = hashmap.begin(); i != hashmap.end(); i++)
            if (i->second == 0)
                answer[0].push_back(i->first);
            else if (i->second == 1)
                answer[1].push_back(i->first);

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        
        return answer;
    }
};

int main() {

    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    
    cout << "Input: matches = " << matches << endl;
    
    cout << "Output: " << Solution().findWinners(matches) << endl;

    return 0;
}
