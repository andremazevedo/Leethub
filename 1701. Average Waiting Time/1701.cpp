#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0;
        int time = 1;

        for (auto& customer : customers) {
            time = max(time, customer[0]);
            int waitingTime = max(0, time - customer[0]) + customer[1];
            sum += waitingTime;
            time += customer[1];
        }

        return sum / customers.size();
    }
};

int main() {

    vector<vector<int>> customers = {{1,2},{2,5},{4,3}};
    
    printInput(getName(customers), customers);

    printOutput(Solution().averageWaitingTime(customers));

    return 0;
}
