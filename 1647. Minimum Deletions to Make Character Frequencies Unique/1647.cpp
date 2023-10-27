#include "../streamUtils.hpp"
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int minimum = 0;
        unordered_map<char, int> frequencyMap;

        for (char c : s)
            frequencyMap[c]++;

        unordered_map<int, vector<char>> characterMap;
        vector<int> frequencies;
        for (pair<char, int> p: frequencyMap) {
            characterMap[p.second].push_back(p.first);
            frequencies.push_back(p.second);
        }

        int i = 1;
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        while (i < frequencies.size()) {
            if (frequencies[i] != 0 && frequencies[i - 1] == frequencies[i]) {
                frequencies[i]--;
                sort(frequencies.begin() + i, frequencies.end(), greater<int>());
                minimum++;
            } else {
                ++i;
            }
        }

        return minimum;
    }
};

int main() {

    // string s = "aab";
    // string s = "aaabbbcc";
    // string s = "ceabaacb";
    // string s = "abcabc";
    string s = "bbcebab";
    
    cout << "Input: s = " << s << endl;
    
    cout << "output: " << Solution().minDeletions(s) << endl;

    return 0;
}