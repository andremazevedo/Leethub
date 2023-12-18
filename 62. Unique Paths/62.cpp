#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

ostream& operator<<(ostream& os, const vector<vector<int>>& matrix)
{
    os << "[";
    for (size_t row = 0; row < matrix.size(); ++row) {
        os << matrix[row];
        if (row < matrix.size() - 1) {
            os << "," << endl;
        }
    }
    os << "]";
    return os;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        int row = m - 2;
        int col = n - 2;
        while (row != -1 && col != -1) {
            for (int i = row; i > -1; i--)
                dp[i][col] = dp[i + 1][col] + dp[i][col + 1];

            for (int j = col - 1; j > -1; j--)
                dp[row][j] = dp[row + 1][j] + dp[row][j + 1];
            row -= 1;
            col -= 1;
        }

        return dp[0][0];
    }
};

int main() {

    int m = 3;
    int n = 2;
    
    cout << "Input: m = " << m << ", n = " << n << endl;
    
    cout << "Output: " << Solution().uniquePaths(m, n) << endl;

    return 0;

}
