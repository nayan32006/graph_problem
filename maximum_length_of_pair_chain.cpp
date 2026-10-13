#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;

        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int chain_length = 1;
        int curr_end = pairs[0][1];

        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > curr_end) {
                chain_length++;
                curr_end = pairs[i][1];
            }
        }

        return chain_length;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> pairs = {{1, 2}, {7, 8}, {4, 5}};

    int max_len = sol.findLongestChain(pairs);
    cout << "Maximum length of pair chain: " << max_len << endl;

    return 0;
}