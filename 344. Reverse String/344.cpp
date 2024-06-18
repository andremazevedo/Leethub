#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            swap(s[i], s[j]);
    }
};

int main() {

    vector<char> s = {'h','e','l','l','o'};
    
    printInput(getName(s), s);
    
    Solution().reverseString(s);

    printOutput(s);

    return 0;
}
