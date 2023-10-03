#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int i = 1, j = 1;
        bool player = true;

        while (i < colors.size() - 1 && j < colors.size() - 1) {
            if (player) {
                if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') {
                    player = false;
                    colors.erase(i, 1);
                    if ( i > 1 && i == colors.size() - 1) 
                        i--;
                    if (i < j)
                        j--;
                }
                else 
                    i++;
            } else {
                if (colors[j - 1] == 'B' && colors[j] == 'B' && colors[j + 1] == 'B') {
                    player = true;
                    colors.erase(j, 1);
                    if (j > 1 && j == colors.size() - 1)
                        j--;;
                    if (j < i)
                        i--;
                }
                else
                    j++;
            }
        }
        
        return !player;
    }
};

int main() {

    string colors = "AAABABB";
    // string colors = "AAAABBBB";
    
    cout << "Input: colors = " << colors << endl;
    
    cout << "output: " << Solution().winnerOfGame(colors) << endl;

    return 0;
}
