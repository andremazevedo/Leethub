#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                five--;
                ten++;

                if (five < 0)
                    return false;
            }
            else {
                if (ten > 0) {
                    five--;
                    ten--;
                }
                else {
                    five -= 3;
                }

                if (five < 0)
                    return false;
            }
        }

        return true;
    }
};

int main() {

    vector<int> bills = {5,5,5,10,20};
    
    printInput(getName(bills), bills);
    
    printOutput(Solution().lemonadeChange(bills));

    return 0;
}
