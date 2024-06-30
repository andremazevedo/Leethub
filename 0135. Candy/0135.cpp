#include <iostream>
#include <vector>

#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = ratings.size();
        vector<int> candies(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i - 1] < ratings[i]) {
                count += candies[i - 1] - candies[i] + 1;
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; -1 < i; --i) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                count += candies[i + 1] - candies[i] + 1;
                candies[i] = candies[i + 1] + 1;
            }
        }

        return count;
    }
};

int main() {

    vector<int> ratings = {1,0,2};
    // vector<int> ratings = {1,2,2};
    
    cout << "Input: ratings = " << ratings << endl;
    
    cout << "output: " << Solution().candy(ratings) << endl;

    return 0;
}
