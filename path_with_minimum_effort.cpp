#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Effort grid initialized to Infinity
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));

        // Min-Heap stores {effort, {r, c}}
        typedef pair<int, pair<int, int>> P;
        priority_queue<P, vector<P>, greater<P>> pq;

        // Base Case: Source cell (0, 0) effort is 0
        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        // Direction vectors for moving Up, Right, Down, Left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int diff = current.first;
            int r = current.second.first;
            int c = current.second.second;

            // Reached Destination Node
            if (r == rows - 1 && c == cols - 1) {
                return diff;
            }

            // Optimization for stale paths
            if (diff > effort[r][c]) continue;

            // Explore 4 Directional Neighbors
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Boundary check
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    // Maximum effort along this path
                    int next_effort = max(diff, abs(heights[r][c] - heights[nr][nc]));

                    // RELAXATION STEP
                    if (next_effort < effort[nr][nc]) {
                        effort[nr][nc] = next_effort;
                        pq.push({next_effort, {nr, nc}});
                    }
                }
            }
        }

        return 0; // Fallback
    }
};

int main() {
    Solution sol;

    vector<vector<int>> heights1 = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    vector<vector<int>> heights2 = {
        {1, 2, 3},
        {3, 8, 4},
        {5, 3, 5}
    };


    cout << "Test Case 1 Output: " << sol.minimumEffortPath(heights1) << " (Expected: 2)" << endl;
    cout << "Test Case 2 Output: " << sol.minimumEffortPath(heights2) << " (Expected: 1)" << endl;

    return 0;
}