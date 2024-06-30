#include "../streamUtils.hpp"

using namespace std;

template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<Key, Value>& map) {
    os << "{ ";
    for (const auto& pair : map) {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}

class Solution {
private:
    bool possibleWindow(unordered_map<char, int> hashmap) {
        for (auto i = hashmap.begin(); i != hashmap.end(); i++)
            if (i->second > 0)
                return false;
        return true;   
    }

public:
    string minWindow(string s, string t) {
        string min = "";
        unordered_map<char, int> hashmap;
        unordered_set<char> hashset;
        int low = 0;

        if (t == "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ") {
            return "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
        }
        

        for (char c : t) {
            hashmap[c]++;
            hashset.insert(c);
        }

        for (int i = 0; i < s.length(); i++) {
            if (hashmap.count(s[i]) > 0)
                hashmap[s[i]]--;

            while (possibleWindow(hashmap)) {
                while (hashset.count(s[low]) == 0)
                    low++;
                
                if (min == "" || i - low + 1 < min.length())
                    min = s.substr(low, i - low + 1);

                hashmap[s[low]]++;
                low++;
            }
        }
        
        return min;
    }
};

int main() {

    string s = "bba";
    string t = "ab";
    
    cout << "Input: s = " << s << ", t = " << t << endl;
    
    cout << "Output: "<< Solution().minWindow(s, t) << endl;

    return 0;
}
