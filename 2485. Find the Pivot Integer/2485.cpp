#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefixSum(n + 1);
        int sufixSum = 0;

        prefixSum[0] = 0;
        for (int i = 1; i < n + 1; i++)
            prefixSum[i] = prefixSum[i - 1] + i;

        for (int i = n; i >= 1; i--) {
            sufixSum += i;

            if (prefixSum[i] == sufixSum)
                return i;
        }
        
        return -1;
    }
};

int main() {

    int n = 4;
    
    cout << "Input: n = " << n << endl;
    
    cout << "Output: "<< Solution().pivotInteger(n) << endl;

    return 0;
}
