#include "../streamUtils.hpp"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int iback = 0, jback = 0;

        while (i >= 0 || j >= 0) {
            if ((i >= 0 && s[i] == '#') || (j >= 0 && t[j] == '#') || iback != 0 || jback != 0) {
                if (i >= 0 && s[i] == '#') {
                    i--;
                    iback++;
                }
                else if (iback != 0) {
                    i--;
                    iback--;
                }

                if (j >= 0 && t[j] == '#') {
                    j--;
                    jback++;
                } 
                else if (jback != 0) {
                    j--;
                    jback--;
                }
            }
            else {
                if (i < 0 || j < 0 ||s[i] != t[j])
                    return false;
                j--;
                i--;    
            }
        }

        return true;
    }
};

int main() {

    string s = "y#fo##f";
    string t = "y#fx#o##f";
    
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    
    cout << "output: " << boolalpha << Solution().backspaceCompare(s, t) << endl;

    return 0;
}
