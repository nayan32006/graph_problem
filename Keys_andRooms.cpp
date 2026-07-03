#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[room] = true;
        for (int key : rooms[room]) {
            if (!vis[key]) {
                dfs(key, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);

        for (int room : vis) {
            if (!room) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter number of rooms: ";
    cin >> n;

    vector<vector<int>> rooms(n);
    for (int i = 0; i < n; i++) {
        int numKeys;
        cout << "Enter number of keys in room " << i << ": ";
        cin >> numKeys;
        rooms[i].resize(numKeys);
        for (int j = 0; j < numKeys; j++) {
            cin >> rooms[i][j];
        }
    }

    Solution solver;
    bool result = solver.canVisitAllRooms(rooms);

    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}