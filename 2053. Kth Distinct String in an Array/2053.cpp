#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> distinct;
        unordered_map<string, int> seen;

        for (const string& s : arr) {
            seen[s]++;

            if (seen[s] == 1)
                distinct.push_back(s);
            else if (seen[s] == 2)
                distinct.erase(find(distinct.begin(), distinct.end(), s));
        }

        if (k <= distinct.size())
            return distinct[k - 1];
        else
            return "";
    }
};

int main() {

    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;
    
    printInput(getName(arr), arr, getName(k), k);
    
    printOutput(Solution().kthDistinct(arr, k));

    return 0;
}
