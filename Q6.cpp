#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findPaths(vector<vector<int>>& maze, int x, int y, int N, string path, vector<string>& result, vector<vector<bool>>& visited) {
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == 0 || visited[x][y]) {
        return;
    }

    if (x == N - 1 && y == N - 1) {
        result.push_back(path);
        return;
    }

    visited[x][y] = true;

    findPaths(maze, x + 1, y, N, path + 'D', result, visited);
    findPaths(maze, x - 1, y, N, path + 'U', result, visited);
    findPaths(maze, x, y + 1, N, path + 'R', result, visited);
    findPaths(maze, x, y - 1, N, path + 'L', result, visited);

    visited[x][y] = false;
}

vector<string> findPath(vector<vector<int>>& maze, int N) {
    vector<string> result;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    if (maze[0][0] == 1) {
        findPaths(maze, 0, 0, N, "", result, visited);
    }

    sort(result.begin(), result.end());

    return result;
}

int main() {
    int N = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = findPath(maze, N);

    for (const string& path : result) {
        cout << path << " ";
    }

    return 0;
}
