#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int min;
        int n = matrix.size();

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                min = matrix[row - 1][col];

                if (0 < col && matrix[row - 1][col - 1] < min)
                    min = matrix[row - 1][col - 1];

                if (col < n - 1 && matrix[row - 1][col + 1] < min)
                    min = matrix[row - 1][col + 1];
                
                matrix[row][col] += min;
            }
        }

        min = matrix[n - 1][0];
        for (int col = 1; col < n; col++)
            if (matrix[n - 1][col] < min)
                min = matrix[n - 1][col];
        
        return min;
    }
};

int main() {

    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    
    cout << "Input: matrix = " << matrix << endl;
    
    cout << "Output: " << Solution().minFallingPathSum(matrix) << endl;

    return 0;
}
