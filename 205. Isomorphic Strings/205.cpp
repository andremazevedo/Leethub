#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashmapS, hashmapT;

        if (s.length() != t.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            if (hashmapS.count(s[i]) > 0 && hashmapS[s[i]] != t[i])
                return false;
            
            if (hashmapT.count(t[i]) > 0 && hashmapT[t[i]] != s[i])
                return false;

            hashmapS[s[i]] = t[i];
            hashmapT[t[i]] = s[i];
        }
        
        return true;
    }
};

int main() {

    string s = "egg";
    string t = "add";
    
    printInput(getName(s), s, getName(t), t);
    
    printOutput(Solution().isIsomorphic(s, t));

    return 0;
}
