#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> s1;
        stack<char> s2;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                s1.push(s[i]);

            if (s[i] == ')')
                if (!s1.empty())
                    s1.pop();
                else
                    s.erase(i--, 1);
        }
        
        for (int i = s.length() - 1; i >= 0; i--) {
             if (s[i] == ')')
                s2.push(s[i]);

            if (s[i] == '(')
                if (!s2.empty())
                    s2.pop();
                else
                    s.erase(i, 1);
        }
        
        return s;
    }
};

int main() {

    string s = "())()(((";
    
    printInput(getName(s), s);
    
    printOutput(Solution().minRemoveToMakeValid(s));

    return 0;
}
