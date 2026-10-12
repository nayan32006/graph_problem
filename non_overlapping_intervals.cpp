#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removals = 0;
        int last_end_time = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last_end_time) {
                removals++;
            } else {
                last_end_time = intervals[i][1];
            }
        }

        return removals;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {1, 3}, {3, 4}};


    int min_removals = sol.eraseOverlapIntervals(intervals);
    cout << "Minimum intervals to remove: " << min_removals << endl;

    return 0;
}