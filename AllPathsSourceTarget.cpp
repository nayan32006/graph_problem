#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans) {
        int n = graph.size();
        if (node == n - 1) {
            ans.push_back(path);
            return;
        }
        for (auto it : graph[node]) {
            path.push_back(it);
            dfs(it, graph, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        path.push_back(0);
        dfs(0, graph, path, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int numNeighbors;
        cout << "Enter number of neighbors for node " << i << ": ";
        cin >> numNeighbors;
        graph[i].resize(numNeighbors);
        for (int j = 0; j < numNeighbors; j++) {
            cin >> graph[i][j];
        }
    }

    Solution solver;
    vector<vector<int>> result = solver.allPathsSourceTarget(graph);

    cout << "[" << endl;
    for (const auto& path : result) {
        cout << "  [";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}