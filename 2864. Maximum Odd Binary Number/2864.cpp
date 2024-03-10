#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '1') {
                swap(s[i], s[j]);
                i++;
            }
        }

        swap(s[i - 1], s[s.length() - 1]);

        return s;
    }
};

int main() {

    string s = "010";
    
    cout << "Input: s = " << s << endl;
    
    cout << "Output: "<< Solution().maximumOddBinaryNumber(s) << endl;

    return 0;
}
