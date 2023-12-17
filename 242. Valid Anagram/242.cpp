#include "../streamUtils.hpp"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> hashmap;

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            hashmap[s[i]] += 1;
            hashmap[t[i]] -= 1;
        }

        for (auto i = hashmap.begin(); i != hashmap.end(); i++) {
            if (i->second != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {

    string s = "anagram";
    string t = "nagaram";

    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    
    cout << "Output: " << boolalpha << Solution().isAnagram(s, t) << endl;

    return 0;
}
