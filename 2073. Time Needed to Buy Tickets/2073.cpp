#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> q;

        for (int i = 0; i < tickets.size(); i++)
            q.push(i);
        
        while (tickets[k] != 0) {
            tickets[q.front()]--;

            if (tickets[q.front()] != 0)
                q.push(q.front());

            q.pop();
            time++;
        }
        
        return time;
    }
};

int main() {

    vector<int> tickets = {2,3,2};
    int k = 2;
    
    printInput(getName(tickets), tickets, getName(k), k);
    
    printOutput(Solution().timeRequiredToBuy(tickets, k));

    return 0;
}
