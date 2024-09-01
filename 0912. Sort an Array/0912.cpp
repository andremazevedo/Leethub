#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());

        return nums;
    }

private:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && nums[l] > nums[largest])
            largest = l;

        if (r < n && nums[r] > nums[largest])
            largest = r;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
};

int main() {

    vector<int> nums = {5,2,3,1};
    
    printInput(getName(nums), nums);

    printOutput(Solution().sortArray(nums));

    return 0;
}
