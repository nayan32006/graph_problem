#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image,
             vector<vector<bool>>& visited,
             int sr,
             int sc,
             int color,
             int st_color) {

        visited[sr][sc] = true;
        image[sr][sc] = color;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int rows = image.size();
        int cols = image[0].size();

        for(int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            if(nr >= 0 &&
               nc >= 0 &&
               nr < rows &&
               nc < cols &&
               image[nr][nc] == st_color) {

                if(!visited[nr][nc]) {
                    dfs(image, visited, nr, nc, color, st_color);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color) {

        int st_color = image[sr][sc];

        if(image[sr][sc] == color)
            return image;

        vector<vector<bool>> visited(
            image.size(),
            vector<bool>(image[0].size(), false)
        );

        dfs(image, visited, sr, sc, color, st_color);

        return image;
    }
};

int main() {
    Solution solver;
    
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int sr = 1, sc = 1, newColor = 2;
    
    vector<vector<int>> result = solver.floodFill(image, sr, sc, newColor);
    
    for(const auto& row : result) {
        for(int pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }
    
    return 0;
}