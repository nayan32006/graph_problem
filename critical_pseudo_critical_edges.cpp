#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
        components = n;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j])
                rank[root_i]++;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
private:
    int getMSTWeight(int n, const vector<vector<int>>& edges, int skip_edge_index, int force_edge_index) {
        DSU dsu(n);
        int weight = 0;

        if (force_edge_index != -1) {
            dsu.unite(edges[force_edge_index][0], edges[force_edge_index][1]);
            weight += edges[force_edge_index][2];
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip_edge_index) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu.unite(u, v)) {
                weight += w;
            }
        }

        if (dsu.components > 1) return 1e9;
        return weight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        vector<vector<int>> new_edges = edges;
        for (int i = 0; i < m; i++) {
            new_edges[i].push_back(i);
        }

        sort(new_edges.begin(), new_edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int base_mst_weight = getMSTWeight(n, new_edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo_critical;

        for (int i = 0; i < m; i++) {
            int original_index = new_edges[i][3];

            if (getMSTWeight(n, new_edges, i, -1) > base_mst_weight) {
                critical.push_back(original_index);
            } else if (getMSTWeight(n, new_edges, -1, i) == base_mst_weight) {
                pseudo_critical.push_back(original_index);
            }
        }

        return {critical, pseudo_critical};
    }
};

int main() {
    Solution sol;

    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 2},
        {0, 3, 2},
        {0, 4, 3},
        {3, 4, 3},
        {1, 4, 6}
    };


    vector<vector<int>> result = sol.findCriticalAndPseudoCriticalEdges(n, edges);

    cout << "Critical Edges (Indices): ";
    for (int idx : result[0]) cout << idx << " ";
    cout << endl;

    cout << "Pseudo-Critical Edges (Indices): ";
    for (int idx : result[1]) cout << idx << " ";
    cout << endl;

    return 0;
}