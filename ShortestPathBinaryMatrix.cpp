#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        
        if (n == 1) return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int r = current.first;
            int c = current.second;
            int currentSteps = grid[r][c];

            if (r == n - 1 && c == n - 1) {
                return currentSteps;
            }

            for (int i = 0; i < 8; i++) {
                int newR = r + dRow[i];
                int newC = c + dCol[i];

                if (newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 0) {
                    grid[newR][newC] = currentSteps + 1; 
                    q.push({newR, newC});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution solver;

    vector<vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    int result = solver.shortestPathBinaryMatrix(grid);

    cout << "Shortest Path Length: " << result << endl;

    return 0;
}