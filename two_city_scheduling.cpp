#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
        });

        int total_cost = 0;
        int n = costs.size() / 2;

        for (int i = 0; i < costs.size(); i++) {
            if (i < n) {
                total_cost += costs[i][1];
            } else {
                total_cost += costs[i][0];
            }
        }

        return total_cost;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> costs = {
        {10, 20},
        {30, 200},
        {400, 50},
        {30, 20}
    };

    int min_cost = sol.twoCitySchedCost(costs);
    cout << "Minimum total cost: " << min_cost << endl;

    return 0;
}