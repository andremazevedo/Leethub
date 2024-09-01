#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int answer = 0;
        unordered_map<char, int> freq;
        vector<int> pushes;

        for (char c : word)
            freq[c]++;

        for (auto& [c, i] : freq)
            pushes.push_back(i);

        sort(pushes.begin(), pushes.end(), greater<int>());

        for (int i = 0; i < pushes.size(); ++i)
            answer += pushes[i] * (i / 8 + 1);

        return answer;
    }
};

int main() {

    string word = "aabbccddeeffgghhiiiiii";
    
    printInput(getName(word), word);
    
    printOutput(Solution().minimumPushes(word));

    return 0;
}
