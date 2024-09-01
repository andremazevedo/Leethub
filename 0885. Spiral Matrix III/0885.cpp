#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> answer;
        int r = rStart;
        int c = cStart;
        int step = 1;

        answer.push_back({r, c});
        while (answer.size() < rows * cols) {
            for (int i = 0; i < step; i++) {
                c = step % 2 == 0 ? c - 1 : c + 1;
                if (0 <= r && r < rows && 0 <= c && c < cols)
                    answer.push_back({r, c});
            }

            for (int i = 0; i < step; i++) {
                r = step % 2 == 0 ? r - 1 : r + 1;
                if (0 <= r && r < rows && 0 <= c && c < cols)
                    answer.push_back({r, c});
            }

            step++;
        }

        return answer;
    }
};

int main() {

    int rows = 5;
    int cols = 6;
    int rStart = 1;
    int cStart = 4;
    
    printInput(getName(rows), rows, getName(cols), cols, getName(rStart), rStart, getName(cStart), cStart);
    
    printOutput(Solution().spiralMatrixIII(rows, cols, rStart, cStart));

    return 0;
}
