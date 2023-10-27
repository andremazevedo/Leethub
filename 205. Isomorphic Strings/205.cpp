#include "../streamUtils.hpp"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hashmap;
        unordered_set<char> hashset;

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (hashmap.count(s[i]) > 0) {
                if (hashmap[s[i]] != t[i]) {
                    return false;
                }
            }
            else if (hashset.count(t[i]) > 0) {
                return false;
            }
            
            hashmap[s[i]] = t[i];
            hashset.insert(t[i]);
        }
        
        return true;
    }
};

int main() {

    // string s = "egg";
    // string t = "add";
    string s = "badc";
    string t = "baba";
    
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    
    cout << "output: " << boolalpha << Solution().isIsomorphic(s, t) << endl;

    return 0;
}
