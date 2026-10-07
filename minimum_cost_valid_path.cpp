#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_back({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            if (r == m - 1 && c == n - 1) {
                return dist[r][c];
            }

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dx[dir];
                int nc = c + dy[dir];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int edgeWeight = (grid[r][c] == dir + 1) ? 0 : 1;

                    if (dist[r][c] + edgeWeight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + edgeWeight;

                        if (edgeWeight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {1, 1, 1, 1},
        {2, 2, 2, 2}
    };

    vector<vector<int>> grid2 = {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };

    cout << "Min Cost for Grid 1: " << sol.minCost(grid1) << endl;
    cout << "Min Cost for Grid 2: " << sol.minCost(grid2) << endl;

    return 0;
}