#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> dirX = { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int> dirY = { -1, 0, 1, -1, 1, -1, 0, 1 };

    bool isValid(int x, int y, int rows, int cols, vector<vector<bool>>& visited) {
        return (x >= 0 && x < rows&& y >= 0 && y < cols && !visited[x][y]);
    }

    void backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string& current, unordered_set<string>& dictionary, unordered_set<string>& result) {
        if (dictionary.find(current) != dictionary.end()) {
            result.insert(current);
        }

        visited[x][y] = true;

        for (int i = 0; i < 8; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if (isValid(newX, newY, board.size(), board[0].size(), visited)) {
                current.push_back(board[newX][newY]);
                backtrack(board, visited, newX, newY, current, dictionary, result);
                current.pop_back();
            }
        }

        visited[x][y] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, unordered_set<string>& dictionary) {
        unordered_set<string> result;
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                string current;
                current.push_back(board[i][j]);
                backtrack(board, visited, i, j, current, dictionary, result);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};

int main() {
    int N = 1;
    unordered_set<string> dictionary = { "CAT" };
    int R = 3, C = 3;
    vector<vector<char>> board = { {'C','A','P'}, {'A','N','D'}, {'T','I','E'} };

    Solution solution;
    vector<string> foundWords = solution.findWords(board, dictionary);

    for (const string& word : foundWords) {
        cout << word << endl;
    }

    return 0;
}
