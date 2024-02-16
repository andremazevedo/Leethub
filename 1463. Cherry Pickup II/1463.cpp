#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int answer = -1;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];

        for (int row = 1; row < rows; row++) {
            for (int robot1 = 0; robot1 < cols; robot1++) {
                for (int robot2 = 0; robot2 < cols; robot2++) {
                    if (dp[row - 1][robot1][robot2] != -1) {
                        for (int i = -1; i < 2; i++) {
                            for (int j = -1; j < 2; j++) {
                                if ((0 <= robot1 + i && robot1 + i < cols) && (0 <= robot2 + j && robot2 + j < cols)) {
                                    if (robot1 + i == robot2 + j) {
                                        dp[row][robot1 + i][robot2 + j] = max(dp[row][robot1 + i][robot2 + j], dp[row - 1][robot1][robot2] + grid[row][robot1 + i]);
                                    }
                                    else {
                                        dp[row][robot1 + i][robot2 + j] = max(dp[row][robot1 + i][robot2 + j], dp[row - 1][robot1][robot2] + grid[row][robot1 + i] + grid[row][robot2 + j]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int robot1 = 0; robot1 < cols; robot1++) {
            for (int robot2 = 0; robot2 < cols; robot2++) {
                if (answer < dp[rows - 1][robot1][robot2]) {
                    answer = dp[rows - 1][robot1][robot2];
                }
            }
        }
        
        return answer;
    }
};

int main() {

    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    
    cout << "Input: grid = " << grid << endl;
    
    cout << "Output: " << Solution().cherryPickup(grid) << endl;

    return 0;
}
