#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = 1;

        while (mask < num)
            mask = (mask << 1) + 1;

        return num ^ mask;
    }
};

int main() {

    int num = 5;
    
    printInput(getName(num), num);
    
    printOutput(Solution().findComplement(num));

    return 0;
}
