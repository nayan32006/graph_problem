#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap;
        int totalTime = 0;

        for (const auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            if (totalTime + duration <= lastDay) {
                totalTime += duration;
                maxHeap.push(duration);
            } else if (!maxHeap.empty() && maxHeap.top() > duration) {
                totalTime += duration - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(duration);
            }
        }

        return maxHeap.size();
    }
};

int main() {
    Solution sol;

    vector<vector<int>> courses1 = {{100, 200}, {1000, 1250}, {2000, 3200}, {300, 1450}};
    vector<vector<int>> courses2 = {{1, 2}};
    vector<vector<int>> courses3 = {{3, 2}, {4, 3}};


    cout << "Test 1 Output: " << sol.scheduleCourse(courses1) << " (Expected: 3)" << endl;
    cout << "Test 2 Output: " << sol.scheduleCourse(courses2) << " (Expected: 1)" << endl;
    cout << "Test 3 Output: " << sol.scheduleCourse(courses3) << " (Expected: 0)" << endl;

    return 0;
}