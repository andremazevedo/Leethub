#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int content = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i = 0, j = 0; i < g.size() && j < s.size(); j++) {
            if (g[i] <= s[j]) {
                content++;
                i++;
            }
        }
        
        return content;
    }
};

int main() {

    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    
    cout << "Input: g = \"" << g << "\", s = " << s << endl;
    
    cout << "Output: " << Solution().findContentChildren(g, s) << endl;

    return 0;
}
