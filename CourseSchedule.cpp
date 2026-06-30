#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &adj) {
        vis[src] = true;
        recPath[src] = true;

        for (int neighbor : adj[src]) {
            if (!vis[neighbor]) {
                if (isCycle(neighbor, vis, recPath, adj)) {
                    return true;
                }
            } else if (recPath[neighbor]) {
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, recPath, adj)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution solver;
    
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    
    if (solver.canFinish(numCourses, prerequisites)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    vector<vector<int>> cyclicPrerequisites = {{1, 0}, {0, 1}};
    if (solver.canFinish(numCourses, cyclicPrerequisites)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}