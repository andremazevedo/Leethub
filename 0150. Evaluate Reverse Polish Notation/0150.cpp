#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (auto token : tokens) {
            if (token == "+") {
                int a = s.top();
                s.pop();
                s.top() += a;
            }
            else if (token == "-") {
                int a = s.top();
                s.pop();
                s.top() -= a;
            }
            else if (token == "*") {
                int a = s.top();
                s.pop();
                s.top() *= a;
            }
            else if (token == "/") {
                int a = s.top();
                s.pop();
                s.top() /= a;
            }
            else {
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
};

int main() {

    vector<string> tokens = {"2","1","+","3","*"};
    
    cout << "Input: tokens = " << tokens << endl;
    
    cout << "Output: " << Solution().evalRPN(tokens) << endl;

    return 0;
}
