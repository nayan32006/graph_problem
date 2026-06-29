#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n, m;

   
    void dfs(int i, int j, vector<vector<char>>& g) {
      
        if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == '0')
            return;

        
        g[i][j] = '0';

        
        dfs(i + 1, j, g); // नीचे (Down)
        dfs(i - 1, j, g); // ऊपर (Up)
        dfs(i, j + 1, g); // दाएं (Right)
        dfs(i, j - 1, g); // बाएं (Left)
    }

    int numIslands(vector<vector<char>>& g) {
        if (g.empty()) return 0;
        
        n = g.size();    // पंक्तियों की संख्या (Rows)
        m = g[0].size(); // कॉलम की संख्या (Columns)
        int c = 0;       

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (g[i][j] == '1') {
                    c++;         
                    dfs(i, j, g); 
                }
            }
        }
        return c; 
    }
};

int main() {
    int rows, cols;
    cout << "Rows और Columns की संख्या डालें: ";
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    
    cout << "ग्रिड के एलिमेंट्स डालें ('1' जमीन के लिए, '0' पानी के लिए):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    Solution ob;
    int totalIslands = ob.numIslands(grid);

    cout << "\nकुल Islands की संख्या: " << totalIslands << endl;

    return 0;
}