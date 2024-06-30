#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;

        for (int i = s.length() - 1; i >= 0 && !(len != 0 && isspace(s[i])); i--)
            if (isalpha(s[i]))
                len++;
        
        return len;
    }
};

int main() {

    string s = "Hello World";
    
    printInput(getName(s), s);
    
    printOutput(Solution().lengthOfLastWord(s));

    return 0;
}
