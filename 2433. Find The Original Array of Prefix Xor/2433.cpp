#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        
        arr[0] = pref[0];
        for (int i = 1; i < pref.size(); i++)
            arr[i] = pref[i - 1] ^ pref[i];
        
        return arr;
    }
};

int main() {

    vector<int> pref = {5,2,0,3,1};
    
    cout << "Input: pref = " << pref << endl;
    
    cout << "Output: " << Solution().findArray(pref) << endl;

    return 0;
}
