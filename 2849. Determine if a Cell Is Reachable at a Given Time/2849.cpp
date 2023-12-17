#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        return abs(fx - sx) <= t && abs(fy - sy) <= t && !(fx == sx && fy == sy && t == 1);
    }
};

int main() {

    int sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
    
    cout << "Input: sx = " << sx << ", sy = " << sy << ", fx = " << sy << ", fy = " << sy << ", t = " << t << endl;
    
    cout << "Output: " << boolalpha << Solution().isReachableAtTime(sx,sy,fx,fy,t) << endl;

    return 0;
}
