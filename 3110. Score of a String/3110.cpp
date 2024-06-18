#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;

        for (int prev = 0, curr = 1; curr < s.length(); prev++, curr++)
            sum += abs(s[prev] - s[curr]);
        
        return sum;
    }
};

int main() {

    string s = "hello";
    
    printInput(getName(s), s);
    
    printOutput(Solution().scoreOfString(s));

    return 0;
}
