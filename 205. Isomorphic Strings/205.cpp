#include "../streamUtils.hpp"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hashmap;

        for (int i = 0; i < s.size(); i++) {
            if (hashmap.count(t[i]) > 0) {
                if (hashmap[t[i]] != s[i]) {
                    return false;
                }
            } else {
                hashmap[t[i]] = s[i];
            }
        }
        
        return true;
    }
};

int main() {

    // string s = "egg";
    // string t = "add";
    string s = "foo";
    string t = "bar";
    
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    
    cout << "output: " << boolalpha << Solution().isIsomorphic(s, t) << endl;

    return 0;
}
