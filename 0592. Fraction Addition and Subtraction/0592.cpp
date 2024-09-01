#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        istringstream in(expression);
        int numerator = 0, denominator = 1, n, d;
        char slash;

        while (in >> n >> slash >> d) {
            numerator = numerator * d + n * denominator;
            denominator = denominator * d;
            int gdc = abs(__gcd(numerator, denominator));
            numerator /= gdc;
            denominator /= gdc;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};

int main() {

    string expression = "-1/2+1/2";
    
    printInput(getName(expression), expression);
    
    printOutput(Solution().fractionAddition(expression));

    return 0;
}
