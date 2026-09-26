#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        int totalSatisfaction = 0;
        int runningSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (runningSum + satisfaction[i] > 0) {
                runningSum += satisfaction[i];
                totalSatisfaction += runningSum;
            } else {
                break;
            }
        }

        return totalSatisfaction;
    }
};

int main() {
    Solution sol;

    vector<int> sat1 = {-1, -8, 0, 5, -9};
    vector<int> sat2 = {4, 3, 2};
    vector<int> sat3 = {-1, -4, -5};


    cout << "Test 1 Output: " << sol.maxSatisfaction(sat1) << " (Expected: 14)" << endl;
    cout << "Test 2 Output: " << sol.maxSatisfaction(sat2) << " (Expected: 20)" << endl;
    cout << "Test 3 Output: " << sol.maxSatisfaction(sat3) << " (Expected: 0)" << endl;

    return 0;
}