#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    static bool decreasingFrequency (string s, string t) { 
        return s.length() > t.length(); 
    }

public:
    string frequencySort(string s) {
        string t = "";
        unordered_map<char, int> hashmap;
        vector<string> vec;

        for (char c : s)
            hashmap[c]++;

        for (auto p : hashmap)
            vec.push_back(string(p.second, p.first));
        
        sort(vec.begin(), vec.end(), decreasingFrequency);
        
        for (auto s : vec)
            t += s;
        
        return t;
    }
};

int main() {

    string s = "tree";
    
    cout << "Input: s = " << s << endl;
    
    cout << "Output: " << Solution().frequencySort(s) << endl;

    return 0;
}
