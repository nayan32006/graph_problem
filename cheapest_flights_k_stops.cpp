#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> minPrice(n, INT_MAX);

        q.push({0, {src, 0}});
        minPrice[src] = 0;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int stops = current.first;
            int u = current.second.first;
            int cost = current.second.second;

            if (stops > k) continue;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int price = neighbor.second;

                if (cost + price < minPrice[v]) {
                    minPrice[v] = cost + price;
                    q.push({stops + 1, {v, cost + price}});
                }
            }
        }

        return minPrice[dst] == INT_MAX ? -1 : minPrice[dst];
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100}, {1, 2, 100}, {2, 0, 100},
        {1, 3, 600}, {2, 3, 200}
    };
    int src = 0, dst = 3, k = 1;


    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Minimum Cost: " << result << endl;

    return 0;
}