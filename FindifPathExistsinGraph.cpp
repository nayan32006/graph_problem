#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int curr, int end){
        if(curr == end) return true;
        if(vis[curr]) return false;

        vis[curr] = 1;

        for(int i = 0; i < graph[curr].size(); i++){
            if(dfs(graph, vis, graph[curr][i], end)) return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(n, 0);
        return dfs(graph, vis, source, destination);
    }
};

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0;
    int destination = 2;

    Solution solver;
    bool result = solver.validPath(n, edges, source, destination);

    cout << (result ? "true" : "false") << endl;

    return 0;
}