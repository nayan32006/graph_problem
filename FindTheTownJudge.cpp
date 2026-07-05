#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0 && n == 1) 
            return 1;
            
        vector<int> count(n + 1, 0);
        for (auto person : trust) {
            count[person[0]]--;
            count[person[1]]++;
        }

        for (int person = 1; person <= n; person++) {
            if (count[person] == n - 1) return person;
        }
        return -1;
    }
};

int main() {
    int n, m;
    cout << "Enter number of people (N): ";
    cin >> n;
    
    cout << "Enter number of trust relationships: ";
    cin >> m;

    vector<vector<int>> trust(m, vector<int>(2));
    cout << "Enter trust pairs (A B meaning A trusts B):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> trust[i][0] >> trust[i][1];
    }

    Solution solver;
    int judge = solver.findJudge(n, trust);

    cout << "The Town Judge is: " << judge << endl;

    return 0;
}