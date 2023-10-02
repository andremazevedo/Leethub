#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        int ANDoperand = 0;


        for (int i = 1; i < n + 1; i++) {
            int newI = i & ANDoperand;
            int count = 1 + ans[newI];
            ans[i] = count;

            if ((i + 1) % 2 == 0) 
                ANDoperand = i;
        }

        return ans;
    }
};

int main() {

    int n = 5;
    
    cout << "Input: n = " << n << "" << endl;
    
    cout << "output: " << Solution().countBits(n) << endl;

    return 0;

}
