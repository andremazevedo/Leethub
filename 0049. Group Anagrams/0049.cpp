#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, int> hashmap;

        for (auto str : strs) {
            string s = str;
            sort(s.begin(), s.end());

            if (hashmap.count(s) > 0) {
                anagrams[hashmap[s]].push_back(str);
            }
            else {
                anagrams.push_back({str});
                hashmap[s] = anagrams.size() - 1;
            }
        }


        return anagrams;
    }
};

int main() {

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    
    cout << "Input: strs = " << strs << endl;
    
    cout << "Output: " << Solution().groupAnagrams(strs) << endl;

    return 0;
}
