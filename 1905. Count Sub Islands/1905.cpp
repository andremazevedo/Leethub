#include "../streamUtils.hpp"

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        vector<vector<bool>> visited(grid2.size(), vector<bool>(grid2[0].size(), false));

        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    if (dfs(grid1, grid2, visited, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }

private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j) {
        stack<pair<int, int>> s;
        bool isSubIsland = true;

        s.push({i, j});
        visited[i][j] = true;

        while (!s.empty()) {
            auto [x, y] = s.top();
            s.pop();

            if (grid1[x][y] == 0) {
                isSubIsland = false;
            }

            if (x > 0 && grid2[x - 1][y] == 1 && !visited[x - 1][y]) {
                s.push({x - 1, y});
                visited[x - 1][y] = true;
            }

            if (x < grid2.size() - 1 && grid2[x + 1][y] == 1 && !visited[x + 1][y]) {
                s.push({x + 1, y});
                visited[x + 1][y] = true;
            }

            if (y > 0 && grid2[x][y - 1] == 1 && !visited[x][y - 1]) {
                s.push({x, y - 1});
                visited[x][y - 1] = true;
            }

            if (y < grid2[0].size() - 1 && grid2[x][y + 1] == 1 && !visited[x][y + 1]) {
                s.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }

        return isSubIsland;
    }
};

int main() {

    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    
    printInput(getName(grid1), getName(grid2));
    
    printOutput(Solution().countSubIslands(grid1, grid2));

    return 0;
}
