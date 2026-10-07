#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            if (r == m - 1 && c == n - 1) {
                return dist[r][c];
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];

                    if (dist[r][c] + weight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + weight;

                        if (weight == 0) {
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
        {0, 1, 1},
        {1, 1, 0},
        {1, 1, 0}
    };

    vector<vector<int>> grid2 = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0}
    };


    cout << "Min Obstacles Removed for Grid 1: " << sol.minimumObstacles(grid1) << endl;
    cout << "Min Obstacles Removed for Grid 2: " << sol.minimumObstacles(grid2) << endl;

    return 0;
}