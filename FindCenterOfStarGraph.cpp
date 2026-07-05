#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};

int main() {
    int n;
    cout << "Enter total number of nodes: ";
    cin >> n;

    int totalEdges = n - 1;
    vector<vector<int>> edges(totalEdges, vector<int>(2));

    cout << "Enter " << totalEdges << " edges (u v):" << endl;
    for (int i = 0; i < totalEdges; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution solver;
    int center = solver.findCenter(edges);

    cout << "Center of the Star Graph is: " << center << endl;

    return 0;
}