#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> s;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                answer[s.top()] = i - s.top();
                s.pop();
            }
            
            s.push(i);
        }
        
        return answer;
    }
};

int main() {

    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    
    cout << "Input: temperatures = " << temperatures << endl;
    
    cout << "Output: " << Solution().dailyTemperatures(temperatures) << endl;

    return 0;
}
