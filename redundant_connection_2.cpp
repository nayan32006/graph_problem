#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> parent;

public:
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v) {
            return false;
        }

        parent[root_u] = root_v;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> inDegree(n + 1, 0);

        vector<int> candidate1 = {};
        vector<int> candidate2 = {};

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            inDegree[v]++;
            if (inDegree[v] == 2) {
                candidate2 = edge;
            }
        }

        if (!candidate2.empty()) {
            for (auto& edge : edges) {
                if (edge[1] == candidate2[1]) {
                    candidate1 = edge;
                    break;
                }
            }
        }

        DSU dsu(n);

        for (auto& edge : edges) {
            if (!candidate2.empty() && edge == candidate2) {
                continue;
            }

            int u = edge[0];
            int v = edge[1];

            if (!dsu.unite(u, v)) {
                if (!candidate2.empty()) {
                    return candidate1;
                }
                return edge;
            }
        }

        return candidate2;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};


    vector<int> res1 = sol.findRedundantDirectedConnection(edges1);
    cout << "Test 1 Output: [" << res1[0] << ", " << res1[1] << "] (Expected: [2, 3])" << endl;

    vector<int> res2 = sol.findRedundantDirectedConnection(edges2);
    cout << "Test 2 Output: [" << res2[0] << ", " << res2[1] << "] (Expected: [4, 1])" << endl;

    return 0;
}