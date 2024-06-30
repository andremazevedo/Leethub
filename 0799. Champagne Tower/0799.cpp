#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cups;
        for (int i = 0; i <= query_row; ++i)
            cups.push_back(vector<double>(i + 1,0));
        cups[0][0] = poured;

        double left, right;
        for (int i = 1; i <= query_row; ++i) {
            for (int j = 0; j < cups[i].size(); ++j) {
                if (j == 0 || cups[i - 1][j - 1] < 1)
                    left = 0;
                else
                    left = (cups[i - 1][j - 1] - 1) / 2;

                if (j == cups[i].size() - 1 || cups[i - 1][j] < 1)
                    right = 0;
                else
                    right = (cups[i - 1][j] - 1) / 2;

                cups[i][j] = left + right;
            }
        } 
        
        return cups[query_row][query_glass] < 1 ? cups[query_row][query_glass] : 1;
    }
};

int main() {

    int poured = 4;
    int query_row = 2;
    int query_glass = 1;
    
    cout << "Input: poured = " << poured << ", query_row = " << query_row << ", query_glass = " << query_glass << endl;
    
    cout << "output: " << Solution().champagneTower(poured, query_row, query_glass) << endl;

    return 0;
}
