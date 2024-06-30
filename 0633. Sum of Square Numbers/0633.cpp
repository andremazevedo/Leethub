#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = sqrt(c);

        while (i <= j) {
            long sum = pow(i, 2) + pow(j, 2);

            if (sum < c)
                i++;
            else if (sum > c)
                j--;
            else
                return true;
        }

        return false;
    }
};

int main() {

    int c = 5;

    printInput(getName(c), c);

    printOutput(Solution().judgeSquareSum(c));

    return 0;
}
