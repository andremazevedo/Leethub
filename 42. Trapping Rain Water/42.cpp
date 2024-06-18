#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        int maxElevationLeft = 0, maxElevationRight = height.size() - 1;
        stack<int> s;

        for (int i = maxElevationLeft + 1; i <= maxElevationRight; i++) {
            if (height[maxElevationLeft] <= height[i]) {
                while (!s.empty()) {
                    trappedWater += height[maxElevationLeft] - height[s.top()];
                    s.pop();
                }
                maxElevationLeft = i;
            }
            else {
                s.push(i);
            }
        }

        while (!s.empty())
            s.pop();

        for (int i = maxElevationRight - 1; i >= maxElevationLeft; i--) {
            if (height[i] >= height[maxElevationRight]) {
                while (!s.empty()) {
                    trappedWater += height[maxElevationRight] - height[s.top()];
                    s.pop();
                }
                maxElevationRight = i;
            }
            else {
                s.push(i);
            }
        }

        return trappedWater;
    }
};

int main() {

    vector<int> height = {4,2,3};
    
    printInput(getName(height), height);
    
    printOutput(Solution().trap(height));

    return 0;
}
