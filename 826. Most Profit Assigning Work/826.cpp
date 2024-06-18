#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int max = 0;
        vector<pair<int, int>> jobs;

        for (int i = 0; i < difficulty.size(); i++)
            jobs.push_back({difficulty[i], profit[i]});

        sort(jobs.begin(), jobs.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        sort(worker.begin(), worker.end());

        int i = jobs.size() - 1;
        int j = worker.size() - 1;
        while (i >= 0 && j >= 0) {
            if (jobs[i].first <= worker[j]) {
                max += jobs[i].second;
                j--;
            } else {
                i--;
            }
        }

        return max;
    }
};

int main() {

    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};

    printInput(getName(difficulty), difficulty, getName(profit), profit, getName(worker), worker);

    printOutput(Solution().maxProfitAssignment(difficulty, profit, worker));

    return 0;
}
