#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int closeMin = 0, closeMax = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                closeMin++;
                closeMax++;
            }

            if (s[i] == ')') {
                closeMin = max(0, --closeMin);;
                closeMax--;
            }

            if (s[i] == '*') {
                closeMin = max(0, --closeMin);
                closeMax++;
            }

            if (closeMax < 0)
                return false;      
        }

        return closeMin == 0;
    }
};

int main() {

    string s = "()";

    printInput(getName(s), s);
    
    printOutput(Solution().checkValidString(s));

    return 0;
}
