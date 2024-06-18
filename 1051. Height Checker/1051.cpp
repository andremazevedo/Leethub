#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> expected = heights;

        sort(expected.begin(), expected.end());

        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != expected[i])
                count++;

        return count;
    }
};

int main() {

    vector<int> heights = {1, 1, 4, 2, 1, 3};

    printInput(getName(heights), heights);
    
    printOutput(Solution().heightChecker(heights));

    return 0;
}
