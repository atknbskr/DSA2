#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<int>& color, vector<vector<int>>& graph, int n, int col) {
    for (int k = 0; k < n; k++) {
        if (graph[node][k] && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, int n, vector<int>& color, int node) {
    if (node == n) {
        return true;
    }

    for (int col = 1; col <= m; col++) {
        if (isSafe(node, color, graph, n, col)) {
            color[node] = col;
            if (graphColoringUtil(graph, m, n, color, node + 1)) {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

int graphColoring(vector<vector<int>>& graph, int m, int n) {
    vector<int> color(n, 0);
    if (graphColoringUtil(graph, m, n, color, 0)) {
        return 1;
    }
    return 0;
}

int main() {
    int N = 4;
    int M = 3;
    int E = 5;
    vector<pair<int, int>> edges = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };

    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < E; i++) {
        graph[edges[i].first][edges[i].second] = 1;
        graph[edges[i].second][edges[i].first] = 1;
    }

    cout << graphColoring(graph, M, N) << endl;

    return 0;
}
