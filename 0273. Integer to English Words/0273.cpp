#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        string word;
        vector<string> units = {"", "Thousand", "Million", "Billion"};

        if (num == 0)
            return "Zero";

        for (int i = 0; num > 0; ++i) {
            int remainder = num % 1000;
            num /= 1000;

            if (remainder == 0)
                continue;

            string threeeDigitsWord = threeDigitsToWords(remainder);
            
            if (i > 0)
                threeeDigitsWord += " " + units[i];

            if (word.empty())
                word = threeeDigitsWord;
            else
                word = threeeDigitsWord + " " + word;
        }

        return word;
    }

private:
    string threeDigitsToWords(int num) {
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string word;

        int hundred = num / 100;
        int ten = num % 100 / 10;
        int one = num % 10;

        if (hundred > 0)
            word = ones[hundred] + " " + "Hundred";

        if (ten == 1)
            word += (word.empty() ? "" : " ") + teens[one];
        else {
            if (ten > 0)
                word += (word.empty() ? "" : " ") + tens[ten];
            if (one > 0)
                word += (word.empty() ? "" : " ") + ones[one];
        }

        return word;
    }
};

int main() {

    int num = 1234567;
    
    printInput(getName(num), num);
    
    printOutput(Solution().numberToWords(num));

    return 0;
}
