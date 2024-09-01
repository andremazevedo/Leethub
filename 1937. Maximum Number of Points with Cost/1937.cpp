#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> dp(points[0].size());

        for (int col = 0; col < points[0].size(); col++)
            dp[col] = points[0][col];

        for (int row = 1; row < points.size(); row++) {
            vector<long long> newDp(points[0].size());
            vector<long long> left(points[0].size(), 0);
            vector<long long> right(points[0].size(), 0);

            left[0] = dp[0];
            for (int col = 1; col < points[0].size(); col++)
                left[col] = max(dp[col], left[col - 1] - 1);

            right[points[0].size() - 1] = dp[points[0].size() - 1];
            for (int col = points[0].size() - 2; col >= 0; col--)
                right[col] = max(dp[col], right[col + 1] - 1);

            for (int col = 0; col < points[0].size(); col++)
                newDp[col] = max(left[col], right[col]) + points[row][col];

            dp = newDp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {

    vector<vector<int>> points = {{1,2,3},{1,5,1},{3,1,1}};
    
    printInput(getName(points), points);
    
    printOutput(Solution().maxPoints(points));

    return 0;
}
