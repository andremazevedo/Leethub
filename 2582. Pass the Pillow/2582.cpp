#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= 2 * (n - 1);

        return (time < n) ? time + 1 : n - (time % (n - 1));
    }
};

int main() {

    int n = 4;
    int time = 5;
    
    printInput(getName(n), n, getName(time), time);

    printOutput(Solution().passThePillow(n, time));

    return 0;
}
