#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, m = depth;

        for (auto i : s) {
            if (i == '(')
                m = max(m, ++depth);
            else if (i == ')')
                --depth;
        }
        
        return m;
    }
};

int main() {

    string s = "(1+(2*3)+((8)/4))+1";
    
    printInput(getName(s), s);
    
    printOutput(Solution().maxDepth(s));

    return 0;
}
