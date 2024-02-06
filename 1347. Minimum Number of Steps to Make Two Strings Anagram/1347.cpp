#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int steps = 0;
        unordered_map<char, int> hashmap;

        for (int i = 0; i < s.length(); i++)
            hashmap[s[i]]++;

        for (int i = 0; i < t.length(); i++)
            if (hashmap.count(t[i]) && hashmap[t[i]] > 0)
                hashmap[t[i]]--;
            else
                steps++;

        return steps;
    }
};

int main() {

    string s = "bab";
    string t = "aba";
    
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    
    cout << "Output: " << Solution().minSteps(s, t) << endl;

    return 0;
}
