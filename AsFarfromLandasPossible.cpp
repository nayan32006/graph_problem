#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        // 1. Multi-source BFS: सारे जमीन (1) वाले सेल्स को शुरुआत में ही Queue में डालो
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        // अगर ग्रिड में एक भी जमीन नहीं है या पूरा ग्रिड ही जमीन है, तो -1 लौटाओ
        if(q.empty() || q.size() == n * n) return -1;
        
        int distance = -1; // -1 से शुरू करेंगे ताकि जब पहली बार पानी मिले तो दूरी 0 हो जाए
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        // 2. BFS लूप चलाओ
        while(!q.empty()) {
            int size = q.size();
            distance++; // हर एक कदम दूर जाने पर दूरी बढ़ाओ
            
            for(int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                
                int r = current.first;
                int c = current.second;
                
                // अपने 4 पड़ोसियों को चेक करो
                for(int d = 0; d < 4; d++) {
                    int nr = r + dRow[d];
                    int nc = c + dCol[d];
                    
                    // अगर नया सेल ग्रिड के अंदर है और वो पानी (0) है...
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;     // इसे जमीन बना दो (ताकि दोबारा न आएं)
                        q.push({nr, nc});     // और इसे Queue में डाल दो
                    }
                }
            }
        }
        
        return distance;
    }
};

int main() {
    int n;
    cout << "Grid का साइज़ (N) डालो: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Grid के एलिमेंट्स डालो (0 पानी के लिए, 1 जमीन के लिए):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solver;
    int result = solver.maxDistance(grid);

    cout << "Maximum Distance: " << result << endl;

    return 0;
}