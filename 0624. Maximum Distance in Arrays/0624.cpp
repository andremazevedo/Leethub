#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int answer = 0;
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {
            answer = max({answer, abs(arrays[i].back() - minVal), abs(maxVal - arrays[i].front())});
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }

        return answer;
    }
};

int main() {

    vector<vector<int>> arrays = {{1,2,3}, {4,5}, {1,2,3}};
    
    printInput(getName(arrays), arrays);
    
    printOutput(Solution().maxDistance(arrays));

    return 0;
}
