#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<bool>& vis, int& nodeCount, int& edgeCount) {
        vis[node] = true;
        nodeCount++;
        edgeCount += adj[node].size();

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, nodeCount, edgeCount);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodeCount = 0;
                int edgeCount = 0;

                dfs(i, adj, vis, nodeCount, edgeCount);

                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};

int main() {
    int n1 = 6;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};

    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};

    Solution sol;
    cout << sol.countCompleteComponents(n1, edges1) << endl;
    cout << sol.countCompleteComponents(n2, edges2) << endl;

    return 0;
}