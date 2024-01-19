#include "../streamUtils.hpp"

using namespace std;

class Solution {
private:
    unordered_map<int,vector<int>> adj;
    unordered_set<int> visited;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void makeGraph(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node->left != nullptr) {
                s.push(node->left);
                addEdge(node->val, node->left->val);
            }

            if (node->right != nullptr) {
                s.push(node->right);
                addEdge(node->val, node->right->val);
            }
        }
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        int time = 0;
        queue<int> q;

        makeGraph(root);

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            queue<int> nextQ;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto adjacent : adj[node]) {
                    if (visited.count(adjacent) == 0) {
                        visited.insert(adjacent);
                        nextQ.push(adjacent);
                    }
                }
            }

            time++;
            q = nextQ;
        }
        
        return --time;
    }
};

int main() {

    TreeNode *root = makeTree({1,5,3,NULL,4,10,6,9,2});
    int start = 3;
    
    cout << "Input: root = " << root << ", start = " << start << endl;
    
    cout << "Output: " << Solution().amountOfTime(root, start) << endl;

    return 0;
}
