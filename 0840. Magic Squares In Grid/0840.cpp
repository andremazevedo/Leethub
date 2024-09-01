#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        if (row < 3 || col < 3)
            return 0;

        for (int i = 0; i < row - 2; i++)
            for (int j = 0; j < col - 2; j++)
                if (isMagicSquare(grid, i, j))
                    count++;

        return count;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> hashset;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[r + i][c + j] < 1 || 9 < grid[r + i][c + j] || hashset.count(grid[r + i][c + j]))
                    return false;
                else
                    hashset.insert(grid[r + i][c + j]);

        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        for (int i = 0; i < 3; i++)
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != sum)
                return false;

        for (int j = 0; j < 3; j++)
            if (grid[r][c + j] + grid[r + 1][c + j] + grid[r + 2][c + j] != sum)
                return false;

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum)
            return false;

        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)
            return false;

        return true;
    }
};

int main() {

    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    
    printInput(getName(grid), grid);
    
    printOutput(Solution().numMagicSquaresInside(grid));

    return 0;
}
