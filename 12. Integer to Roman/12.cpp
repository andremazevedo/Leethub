#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for (int i = 0; i < symbol.size(); i++) {
            while (num >= value[i]) {
                roman += symbol[i];
                num -= value[i];
            }
        }

        return roman;
    }
};

int main() {

    int num = 1994;
    
    cout << "Input: num = " << num << endl;
    
    cout << "output: \"" << Solution().intToRoman(num) << "\""<< endl;

    return 0;

}
