#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 != 0)
                count++;
            else
                count = 0;

            if (count == 3)
                return true;
        }

        return false;
    }
};

int main() {

    vector<int> arr = {2,6,4,1};
    
    printInput(getName(arr), arr);

    printOutput(Solution().threeConsecutiveOdds(arr));

    return 0;
}
