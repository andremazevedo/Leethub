#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;

        if (n % 2 != 0)
            return false;
        
        return isPowerOfTwo(n >> 1);
    }
};

int main() {

    int n = 1;
    
    cout << "Input: n = " << n << endl;
    
    cout << "Output: " << boolalpha << Solution().isPowerOfTwo(n) << endl;

    return 0;
}
