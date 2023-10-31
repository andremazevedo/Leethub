#include "../streamUtils.hpp"
#include <algorithm>

using namespace std;

bool countBits (int i,int j) { 
    bool isGreater = i < j;

    int iCount = 0;
    while (i) {
        iCount += i & 1;
        i >>= 1;
    }

    int jCount = 0;
    while (j) {
        jCount += j & 1;
        j >>= 1;
    }

    return iCount < jCount || (iCount == jCount && isGreater);
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), countBits);
        return arr;
    }
};

int main() {

    vector<int> arr = {1024,512,256,128,64,32,16,8,4,2,1};
    
    cout << "Input: arr = " << arr << endl;
    
    cout << "Output: " << Solution().sortByBits(arr) << endl;

    return 0;
}
