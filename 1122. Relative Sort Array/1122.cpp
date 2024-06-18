#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int i = 0;
        for (int j = 0; j < arr2.size(); j++)
            for (int k = 0; k < arr1.size(); k++)
                if (arr1[k] == arr2[j])
                    swap(arr1[i++], arr1[k]);

        sort(arr1.begin() + i, arr1.end());

        return arr1;
    }
};

int main() {

    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    printInput(getName(arr1), arr1, getName(arr2), arr2);

    printOutput(Solution().relativeSortArray(arr1, arr2));

    return 0;
}
