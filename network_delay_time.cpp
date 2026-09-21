#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build Adjacency List (1-based indexing)
        // adj[u] = {{v1, w1}, {v2, w2}}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // Step 2: Min-Heap for Dijkstra -> {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 3: Distance Array Initialized to Infinity
        vector<int> dist(n + 1, INT_MAX);

        // Distance to source node 'k' is 0
        dist[k] = 0;
        pq.push({0, k});

        // Step 4: Process Min-Heap
        while (!pq.empty()) {
            int current_time = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Optimization for stale states
            if (current_time > dist[u]) continue;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // RELAXATION STEP
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 5: Find maximum time taken among all reachable nodes
        int maxDelay = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; // Unreachable node
            maxDelay = max(maxDelay, dist[i]);
        }

        return maxDelay;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n1 = 4, k1 = 2;

    vector<vector<int>> times2 = {{1, 2, 1}};
    int n2 = 2, k2 = 1;
    vector<vector<int>> times3 = {{1, 2, 1}};
    int n3 = 2, k3 = 2;


    cout << "Test 1 (Source node " << k1 << "): " << sol.networkDelayTime(times1, n1, k1) << " (Expected: 2)" << endl;
    cout << "Test 2 (Source node " << k2 << "): " << sol.networkDelayTime(times2, n2, k2) << " (Expected: 1)" << endl;
    cout << "Test 3 (Source node " << k3 << "): " << sol.networkDelayTime(times3, n3, k3) << " (Expected: -1)" << endl;

    return 0;
}