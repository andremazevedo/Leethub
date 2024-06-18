#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxRectangle = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dpHorizontal(rows, vector<int>(cols, 0));
        vector<vector<int>> dpVertical(rows, vector<int>(cols, 0));
        
        for (int row = 0; row < rows; row++) {
            for (int col = cols - 1; col >= 0; col--) {
                if (matrix[row][col] == '1') {
                    dpHorizontal[row][col] = (col + 1 < cols ? dpHorizontal[row][col + 1] : 0) + 1;
                }
            }
        }

        for (int col = 0; col < cols; col++) {
            for (int row = rows - 1; row >= 0; row--) {
                if (matrix[row][col] == '1') {
                    dpVertical[row][col] = (row + 1 < rows ? dpVertical[row + 1][col] : 0) + 1;
                }
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int height = dpVertical[row][col];
                
                for (int width = 1; width <= dpHorizontal[row][col]; width++) {
                    height = min(height, dpVertical[row][col + width - 1]);
                    maxRectangle = max(maxRectangle, width * height);
                }
            }    
        }
        
        return maxRectangle;
    }
};

int main() {

    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    printInput(getName(matrix), matrix);
    
    printOutput(Solution().maximalRectangle(matrix));

    return 0;
}
