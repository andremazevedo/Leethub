#include "../streamUtils.hpp"
#include <cmath>

using namespace std;

class Solution {
private:
    int invert = false;

public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return invert ? 1 : 0;
        } else {
            if (k > pow(2, n - 2)) {
                invert = !invert;
                return kthGrammar(n - 1, k - pow(2, n - 2));
            } else {
                return kthGrammar(n - 1, k);
            }
        }
    }
};

int main() {

    int n = 3;
    int k = 4;
    
    cout << "Input: n = " << n << ", k = " << k << endl;
    
    cout << "Output: " << Solution().kthGrammar(n, k) << endl;

    return 0;
}
