#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;

        if (n == 0 || (n & 3) != 0)
            return false;

        return isPowerOfFour(n >> 2);
    }
};

int main() {

    int n = 6;
    
    cout << "Input: n = " << n << endl;
    
    cout << "output: " << boolalpha << Solution().isPowerOfFour(n) << endl;

    return 0;
}
