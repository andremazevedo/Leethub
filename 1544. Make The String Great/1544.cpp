#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int i = 0;

        while (!s.empty() && i < s.length() - 1) {
            if (abs(s[i] - s[i + 1]) == 'a' - 'A') {
                s.erase(i, 2);
                
                if (i > 0)
                    i--;
            }
            else {
                i++;
            }
        }
        
        return s;
    }
};

int main() {

    string s = "abBAcC";
    
    printInput(getName(s), s);
    
    printOutput(Solution().makeGood(s));

    return 0;
}
