#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
            if (i < n) {
                dist[i][i + 1] = 1;
                dist[i + 1][i] = 1;
            }
        }

        dist[x][y] = min(dist[x][y], 1);
        dist[y][x] = min(dist[y][x], 1);

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        vector<int> result(n, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    int d = dist[i][j];
                    result[d - 1]++;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n1 = 3, x1 = 1, y1 = 3;
    int n2 = 5, x2 = 2, y2 = 4;


    vector<int> res1 = sol.countOfPairs(n1, x1, y1);
    cout << "Result for n=" << n1 << ", x=" << x1 << ", y=" << y1 << ":" << endl;
    for (int count : res1) cout << count << " ";
    cout << endl;

    vector<int> res2 = sol.countOfPairs(n2, x2, y2);
    cout << "\nResult for n=" << n2 << ", x=" << x2 << ", y=" << y2 << ":" << endl;
    for (int count : res2) cout << count << " ";
    cout << endl;

    return 0;
}