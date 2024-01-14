#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_set<char> hashset1;
        unordered_map<int,int> hashmap1;
        unordered_set<char> hashset2;
        unordered_map<int,int> hashmap2;

        if (word1.length() != word2.length())
            return false;

        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        char c = word1[0];
        int times = 1;
        hashset1.insert(c);
        for (int i = 1; i < word1.length(); i++) {
            if (c != word1[i]) {
                hashmap1[times]++;
                c = word1[i];
                times = 1;
                hashset1.insert(c);
            } else {
                times++;
            }
        }
        hashmap1[times]++;

        c = word2[0];
        times = 1;
        if (hashset1.count(c) <= 0)
                return false;
        hashset2.insert(c);
        for (int i = 1; i < word2.length(); i++) {
            
            if (c != word2[i]) {
                hashmap2[times]++;
                c = word2[i];
                times = 1;
                if (hashset1.count(c) <= 0)
                    return false;
                hashset2.insert(c);
            } else {
                times++;
            }
        }
        hashmap2[times]++;

        for (auto i = hashmap1.begin(); i != hashmap1.end(); i++)
            if (i->second != hashmap2[i->first])
                return false;

        return true;
    }
};

int main() {

    string word1 = "uau";
    string word2 = "ssx";
    
    cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << endl;
    
    cout << "Output: " << boolalpha << Solution().closeStrings(word1, word2) << endl;

    return 0;
}
