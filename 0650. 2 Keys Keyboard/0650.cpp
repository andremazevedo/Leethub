#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;

        int i = n / 2;
        while (i >= 1) {
            if (n % i == 0)
                break;
            i--;
        }

        return n / i + minSteps(i);
    }
};

int main() {

    int n = 3;
    
    printInput(getName(n), n);
    
    printOutput(Solution().minSteps(n));

    return 0;
}
