#include "../streamUtils.hpp"
#include <algorithm>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        for (int i = 0; i < 2; i++) {
            int min = i;
            for (int j = i + 1; j < prices.size(); j++)
                if (prices[j] < prices[min]) 
                    min = j;
            swap(prices[i], prices[min]);
        }

        return (money >= prices[0] + prices[1]) ? (money - prices[0] - prices[1]) : money;      
    }
};

int main() {

    vector<int> prices = {1,2,2};
    int money = 3;
    
    cout << "Input: prices = " << prices << ", money = " << money << endl;
    
    cout << "Output: " << Solution().buyChoco(prices, money) << endl;

    return 0;
}
