#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build Adjacency List and Indegree Array
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course); // prereq -> course
            indegree[course]++;
        }

        // Push all nodes with 0 indegree into Queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        // BFS Traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Check if cycle exists
        if (topoOrder.size() == numCourses) {
            return topoOrder;
        }

        return {}; // Impossible to complete all courses
    }
};

int main() {
    int numCourses, p;
    cout << "Enter number of courses: ";
    if (!(cin >> numCourses) || numCourses <= 0) return 0;

    cout << "Enter number of prerequisite pairs: ";
    cin >> p;

    vector<vector<int>> prerequisites(p, vector<int>(2));
    cout << "Enter prerequisite pairs (course prerequisite):\n";
    for (int i = 0; i < p; ++i) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Solution sol;
    vector<int> result = sol.findOrder(numCourses, prerequisites);

    cout << "\nCourse Order:\n";
    if (result.empty()) {
        cout << "[] (Impossible to complete all courses due to cycle)" << endl;
    } else {
        cout << "[ ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}