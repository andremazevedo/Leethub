#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;

        for (int i = 1; i < 10; i++) {
            int n = i;
            
            for (int j = i + 1; j <= 10; j++) {
                if (high < n)
                    break;

                if (low <= n)
                    answer.push_back(n);

                n = n * 10 + j;
            }
        }
        
        sort(answer.begin(), answer.end());

        return answer;
    }
};

int main() {

    int low = 100;
    int high = 300;
    
    cout << "Input: low = " << low << ", high = " << high << endl;
    
    cout << "Output: "<< Solution().sequentialDigits(low, high) << endl;

    return 0;
}
