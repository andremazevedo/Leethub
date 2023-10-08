#include "../streamUtils.hpp"
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashset;

        while (hashset.count(n) == 0) {
            hashset.insert(n);

            int i = 0;
            while (n) {
                i += pow(n % 10, 2);
                n /= 10;
            }

            if ((n = i) == 1)
                return true;
        }
        
        return false;
    }
};

int main() {

    int n = 19;
    
    cout << "Input: n = " << n << endl;
    
    cout << "output: " << boolalpha << Solution().isHappy(n) << endl;

    return 0;
}
