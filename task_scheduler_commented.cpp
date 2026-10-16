#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int max_freq = 0;

        for (char task : tasks) {
            freq[task - 'A']++;
            max_freq = max(max_freq, freq[task - 'A']);
        }

        int max_count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == max_freq) {
                max_count++;
            }
        }

        int total_slots = (max_freq - 1) * (n + 1) + max_count;
        return max((int)tasks.size(), total_slots);
    }
};

int main() {
    Solution sol;

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;


    int min_time = sol.leastInterval(tasks, n);
    cout << "Minimum units of time required: " << min_time << endl;

    return 0;
}