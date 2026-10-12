#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int arrow_pos = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > arrow_pos) {
                arrows++;
                arrow_pos = points[i][1];
            }
        }

        return arrows;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points = {{1, 6}, {2, 8}, {7, 12}, {10, 16}};


    int min_arrows = sol.findMinArrowShots(points);
    cout << "Minimum arrows required: " << min_arrows << endl;

    return 0;
}