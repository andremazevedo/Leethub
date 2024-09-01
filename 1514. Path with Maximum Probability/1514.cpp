#include "../streamUtils.hpp"

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        vector<double> prob(n, 0.0);
        priority_queue<pair<double, int>> pq;

        prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        while (!pq.empty()) {
            auto [p, node] = pq.top();
            pq.pop();

            if (node == end_node)
                return p;

            for (int i = 0; i < adj[node].size(); i++) {
                int next = adj[node][i].first;
                double next_p = adj[node][i].second;
                double new_p = p * next_p;

                if (new_p > prob[next]) {
                    prob[next] = new_p;
                    pq.push({new_p, next});
                }
            }
        }

        return 0.0;
    }
};

int main() {

    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start_node = 0;
    int end_node = 2;
    
    printInput(getName(n), n, getName(edges), edges, getName(succProb), succProb, getName(start_node), start_node, getName(end_node), end_node);
    
    printOutput(Solution().maxProbability(n, edges, succProb, start_node, end_node));

    return 0;
}

