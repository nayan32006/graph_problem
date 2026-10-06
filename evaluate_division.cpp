#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool dfs(const string& src, const string& target, double current_product,
             unordered_map<string, vector<pair<string, double>>>& adj,
             unordered_set<string>& visited, double& result) {
        
        visited.insert(src);

        if (src == target) {
            result = current_product;
            return true;
        }

        for (const auto& neighbor : adj[src]) {
            string next_node = neighbor.first;
            double weight = neighbor.second;

            if (visited.find(next_node) == visited.end()) {
                if (dfs(next_node, target, current_product * weight, adj, visited, result)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> results;

        for (const auto& query : queries) {
            string src = query[0];
            string target = query[1];

            if (adj.find(src) == adj.end() || adj.find(target) == adj.end()) {
                results.push_back(-1.0);
            } else if (src == target) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double res = -1.0;
                dfs(src, target, 1.0, adj, visited, res);
                results.push_back(res);
            }
        }

        return results;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};


    vector<double> results = sol.calcEquation(equations, values, queries);

    cout << "Query Results:" << endl;
    for (int i = 0; i < queries.size(); i++) {
        cout << queries[i][0] << " / " << queries[i][1] << " = " << results[i] << endl;
    }

    return 0;
}