#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> max_heap;
        int current_fuel = startFuel;
        int stops = 0;
        int i = 0;
        int n = stations.size();

        while (current_fuel < target) {
            while (i < n && stations[i][0] <= current_fuel) {
                max_heap.push(stations[i][1]);
                i++;
            }

            if (max_heap.empty()) {
                return -1;
            }

            current_fuel += max_heap.top();
            max_heap.pop();
            stops++;
        }

        return stops;
    }
};

int main() {
    Solution sol;

    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40}
    };


    int result = sol.minRefuelStops(target, startFuel, stations);
    cout << "Minimum refueling stops required: " << result << endl;

    return 0;
}