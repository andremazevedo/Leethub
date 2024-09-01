#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for (string detail : details) {
            int age = stoi(detail.substr(11, 2));
            if (age > 60)
                count++;
        }

        return count;
    }
};

int main() {

    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    
    printInput(getName(details), details);

    printOutput(Solution().countSeniors(details));

    return 0;
}
