#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;

        for (char c : s)
            hashmap[c]++;

        for (int i = 0; i < s.size(); i++)
            if (hashmap[s[i]] == 1)
                return i;
        
        return -1;
    }
};

int main() {

    string s = "";
    
    cout << "Input: s = " << s << endl;
    
    cout << "Output: " << Solution().firstUniqChar(s) << endl;

    return 0;
}
