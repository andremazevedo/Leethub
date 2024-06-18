#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector<int> group;

        if (hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        for (auto it = hand.begin(); it != hand.end();) {
            cout << "it: " << *it << endl;
            if (group.empty()) {
                group.push_back(*it);
                it = hand.erase(it);
            }
            else if (group.back() + 1 == *it) {
                group.push_back(*it);
                it = hand.erase(it);
            }
            else if (group.back() == *it) {
                it++;
            }
            else {
                return false;
            }

            if (group.size() == groupSize) {
                group.clear();
                it = hand.begin();
            }

            if (it == hand.end() && !hand.empty())
                return false;
        }
        
        return true;
    }
};

int main() {

    vector<int> hand = {1,1,2,2,3,3};
    int groupSize = 2;

    printInput(getName(hand), hand, getName(groupSize), groupSize);
    
    printOutput(Solution().isNStraightHand(hand, groupSize));

    return 0;
}
