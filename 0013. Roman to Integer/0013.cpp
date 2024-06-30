#include <iostream>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int n = 0;

        int i = 0;
        while (i < s.size()) {
            if(s[i] == 'M') {
                n += 1000;
            }
            else if (s[i] == 'D') {
                n += 500;
            }
            else if (s[i] == 'C') {
                if (i + 1 < s.size() && (s[i + 1] == 'M' || s[i + 1] == 'D')) 
                    n -= 100;
                else
                    n += 100;
            }
            else if (s[i] == 'L') {
                n += 50;
            }
            else if (s[i] == 'X') {
                if (i + 1 < s.size() && (s[i + 1] == 'C' || s[i + 1] == 'L')) 
                    n -= 10;
                else
                    n += 10;
            }
            else if (s[i] == 'V') {
                n += 5;
            }
            else if (s[i] == 'I') {
                if (i + 1 < s.size() && (s[i + 1] == 'X' || s[i + 1] == 'V')) 
                    n -= 1;
                else
                    n += 1;
            }
            i++;
        }
        
        return n;
    }
};


int main() {

    // string s = "II"; 
    // string s = "LVIII";
    string s = "MCMXCIV";
    
    cout << "Input: s = \"" << s << "\"" << endl;
    
    cout << "output: " << Solution().romanToInt(s) << endl;

    return 0;

}
