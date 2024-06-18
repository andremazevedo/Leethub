#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j])
                j++;
            i++;
        }
        return  t.size() - j;
    }
};

int main() {

    string s = "coaching";
    string t = "coding";
    
    printInput(getName(s), s, getName(t), t);

    printOutput(Solution().appendCharacters(s, t));

    return 0;
}
