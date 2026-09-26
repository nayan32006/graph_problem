#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;

        for (char t : tasks) {
            freq[t - 'A']++;
            maxFreq = max(maxFreq, freq[t - 'A']);
        }

        int maxFreqCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxFreqCount++;
            }
        }

        int totalSlots = (maxFreq - 1) * (n + 1) + maxFreqCount;
        return max((int)tasks.size(), totalSlots);
    }
};

int main() {
    Solution sol;

    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;

    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n2 = 1;


    cout << "Test 1 Output: " << sol.leastInterval(tasks1, n1) << " (Expected: 8)" << endl;
    cout << "Test 2 Output: " << sol.leastInterval(tasks2, n2) << " (Expected: 6)" << endl;

    return 0;
}