#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle(numRows);
        
        for (int i = 0; i < numRows; ++i) {
            pascalTriangle[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            }
        }
        
        return pascalTriangle;
    }
};

int main() {

    int numRows = 5;
    
    cout << "Input: numRows = " << numRows << endl;
    
    cout << "Output: " << Solution().generate(numRows) << endl;

    return 0;
}