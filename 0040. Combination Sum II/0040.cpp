#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, path, answer);

        return answer;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& answer) {
        if (target == 0) {
            answer.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (start < i && candidates[i - 1] == candidates[i])
                continue;
            
            if (target < candidates[i])
                break;

            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, path, answer);
            path.pop_back();
        }
    }
};

int main() {

    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    
    printInput(getName(candidates), candidates, getName(target), target);
    
    printOutput(Solution().combinationSum2(candidates, target));
    return 0;
}
