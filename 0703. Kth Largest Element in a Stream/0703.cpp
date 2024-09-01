#include "../streamUtils.hpp"

using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums)
            pq.push(num);

        while (pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};

int main() {

    int k = 3;
    vector<int> nums = {4,5,8,2};

    KthLargest* obj = new KthLargest(k, nums);
    int param_1 = obj->add(3);
    int param_2 = obj->add(5);
    int param_3 = obj->add(10);
    int param_4 = obj->add(9);
    int param_5 = obj->add(4);

    return 0;
}
