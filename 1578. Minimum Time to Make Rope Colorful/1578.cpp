#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int min = 0;

        int i = 0, j = 1;
        while (j < colors.size()) {
            if (colors[i] == colors[j]) {
                if (neededTime[i] < neededTime[j]) {
                    min += neededTime[i];
                    i = j;
                }
                else
                    min += neededTime[j];
            }
            else
                i = j;

            j++;
        }
        
        return min;
    }
};

int main() {

    string colors = "abaac";
    vector<int> neededTime = {1,2,3,4,5};
    
    cout << "Input: colors = \"" << colors << "\", neededTime = " << neededTime << endl;
    
    cout << "Output: " << Solution().minCost(colors, neededTime) << endl;

    return 0;
}
