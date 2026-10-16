#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int n = heights.size();

        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0) continue;

            min_heap.push(diff);

            if (min_heap.size() > ladders) {
                bricks -= min_heap.top();
                min_heap.pop();
            }

            if (bricks < 0) return i;
        }

        return n - 1;
    }
};

int main() {
    Solution sol;

    vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    int bricks = 5;
    int ladders = 1;


    int furthest = sol.furthestBuilding(heights, bricks, ladders);
    cout << "Furthest building index you can reach: " << furthest << endl;

    return 0;
}