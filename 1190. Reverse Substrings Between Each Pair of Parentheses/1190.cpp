#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string answer = "";
        stack<stack<char>> stacks;

        for (char c : s) {
            if (c == '(') {
                stacks.push(stack<char>());
            } 
            else if (c == ')') {
                stack<char> temp = stacks.top();
                stacks.pop();

                while (!temp.empty()) {
                    if (stacks.empty())
                        answer += temp.top();
                    else
                        stacks.top().push(temp.top());

                    temp.pop();
                }
            }
            else if (!stacks.empty()) {
                stacks.top().push(c);
            }
            else {
                answer += c;
            }
        }

        return answer;
    }
};;

int main() {

    string s = "a(bcdefghijkl(mno)p)q";
    
    printInput(getName(s), s);

    printOutput(Solution().reverseParentheses(s));

    return 0;
}
