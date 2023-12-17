#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        
        int i = 0, j = 1;
        while (j <= n && i < target.size()) {
            operations.push_back("Push");
            if (target[i] == j)
                i++;
            else
                operations.push_back("Pop");
            j++;
        }

        return operations;
    }
};

int main() {

    vector<int> target = {1,2};
    int n = 4;
    
    cout << "Input: target = " << target << ", n = " << n << endl;
    
    cout << "Output: "<< Solution().buildArray(target, n) << endl;

    return 0;
}
