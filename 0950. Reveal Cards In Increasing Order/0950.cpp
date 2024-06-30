#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> deckDeque;

        sort(deck.begin(), deck.end());

        for (int i = deck.size() - 1; i >= 0; i--) {
            if (!deckDeque.empty()) {
                deckDeque.push_front(deckDeque.back());
                deckDeque.pop_back();
            }
            
            deckDeque.push_front(deck[i]);
        }
        
        return vector<int>(deckDeque.begin(), deckDeque.end());
    }
};

int main() {

    vector<int> deck = {17,13,11,2,3,5,7};
    
    printInput(getName(deck), deck);
    
    printOutput(Solution().deckRevealedIncreasing(deck));

    return 0;
}
