#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;

        while (k > 0) {
            while (i < num.size() - 1 && num[i] <= num[i + 1]) 
                i++;

            num.erase(num.begin() + i);

            if (i > 0) 
                i--;

            k--;
        }

        while (num[0] == '0')
            num.erase(num.begin());
        
        return num == "" ? "0" : num;
    }
};

int main() {

    string num = "1432219";
    int k = 3;
    
    printInput(getName(num), num, getName(k), k);
    
    printOutput(Solution().removeKdigits(num, k));

    return 0;
}
