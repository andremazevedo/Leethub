#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> common;
        unordered_map<char, int> prevFreq;

        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> freq;
            unordered_map<char, int> commonFreq;

            for (auto c : words[i])
                freq[c]++;
            
            if (i == 0)
                commonFreq = freq;
            else
                for (auto &prev : prevFreq)
                    if (freq.count(prev.first) > 0)
                        commonFreq[prev.first] = min(prev.second, freq[prev.first]);

            prevFreq = commonFreq;
        }

        for (auto &p : prevFreq)
            for (int i = 0; i < p.second; i++)
                common.push_back(string(1, p.first));
        
        return common;
    }
};

int main() {

    vector<string> words = {"acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd"};

    printInput(getName(words), words);
    
    printOutput(Solution().commonChars(words));

    return 0;
}
