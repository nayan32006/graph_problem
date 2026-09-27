#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));

        for (const auto& pre : prerequisites) {
            isPrereq[pre[0]][pre[1]] = true;
        }

        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (isPrereq[i][k] && isPrereq[k][j]) {
                        isPrereq[i][j] = true;
                    }
                }
            }
        }

        vector<bool> result;
        for (const auto& q : queries) {
            result.push_back(isPrereq[q[0]][q[1]]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    int numCourses1 = 2;
    vector<vector<int>> pre1 = {{1, 0}};
    vector<vector<int>> queries1 = {{0, 1}, {1, 0}};

    int numCourses2 = 3;
    vector<vector<int>> pre2 = {{1, 2}, {2, 0}};
    vector<vector<int>> queries2 = {{1, 0}, {0, 1}};


    vector<bool> res1 = sol.checkIfPrerequisite(numCourses1, pre1, queries1);
    cout << "Test 1 Output: [";
    for (int i = 0; i < res1.size(); i++) cout << (res1[i] ? "true" : "false") << (i == res1.size() - 1 ? "" : ", ");
    cout << "] (Expected: [false, true])" << endl;

    vector<bool> res2 = sol.checkIfPrerequisite(numCourses2, pre2, queries2);
    cout << "Test 2 Output: [";
    for (int i = 0; i < res2.size(); i++) cout << (res2[i] ? "true" : "false") << (i == res2.size() - 1 ? "" : ", ");
    cout << "] (Expected: [true, false])" << endl;

    return 0;
}