#include "../streamUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer(n);
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);
        
            while (!q.empty()) {
                int from = q.front();
                q.pop();

                for (int to : adj[from]) {
                    if (!visited[to]) {
                        answer[to].push_back(i);
                        q.push(to);
                        visited[to] = true;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {

    int n = 8;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};

    printInput(getName(n), n, getName(edges), edges);
    
    printOutput(Solution().getAncestors(n, edges));

    return 0;
}
