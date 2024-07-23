#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = numBottles;

        while (numBottles >= numExchange) {
            answer += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }

        return answer;
    }
};

int main() {

    int numBottles = 9;
    int numExchange = 3;
    
    printInput(getName(numBottles), numBottles, getName(numExchange), numExchange);

    printOutput(Solution().numWaterBottles(numBottles, numExchange));

    return 0;
}
