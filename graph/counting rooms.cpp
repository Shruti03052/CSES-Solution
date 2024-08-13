#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>> &room, int n, int m) {
    visited[r][c] = 1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nrow = r + dx[i];
        int ncol = c + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]) {
            if (room[nrow][ncol] == '.') {
                dfs(nrow, ncol, visited, room, n, m);
            }
        }
    }
}

int count_rooms(int n, int m, vector<vector<char>> &room) {
    int cnt = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && room[i][j] == '.') {
                cnt++;
                dfs(i, j, visited, room, n, m);
            }
        }
    }

    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> room(n, vector<char>(m));  // Initialize the room with the correct size

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    int result = count_rooms(n, m, room);
    cout << result << endl;  // Output the result

    return 0;
}
