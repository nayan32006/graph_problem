#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(n, false);
        vector<int> minCost(n, INT_MAX);

        pq.push({0, 0});
        minCost[0] = 0;

        int totalCost = 0;
        int edgesConnected = 0;

        while (!pq.empty() && edgesConnected < n) {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int u = top.second;

            if (inMST[u]) continue;

            inMST[u] = true;
            totalCost += cost;
            edgesConnected++;

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                    if (dist < minCost[v]) {
                        minCost[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return totalCost;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    vector<vector<int>> points2 = {{3, 12}, {-2, 5}, {-4, 1}};

    cout << "Test Case 1 Output: " << sol.minCostConnectPoints(points1) << " (Expected: 20)" << endl;
    cout << "Test Case 2 Output: " << sol.minCostConnectPoints(points2) << " (Expected: 18)" << endl;

    return 0;
}