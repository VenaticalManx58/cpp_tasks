#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool is_valid(vector<string> &board, int row, int col) {
    // проверка можно ли сюда поставить королеву
    int n = board.size();
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    // 
    for (int i = row - 1, j = col -1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void rec(vector<vector<string>> &result, vector<string> &board, int row) {
    int n = board.size();
    if (row == n) {
        result.push_back(board);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (is_valid(board, row, j)) {
            board[row][j] = 'Q';
            rec(result, board, row+1);
            board[row][j] = '.';
        }
    }

    
}

vector<vector<string>> solve(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result;
    rec(result, board, 0);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> result = solve(n);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << "[\"";
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
            if (j != n - 1) {
                cout << "\",\"";
            }
        }
        cout << "\"]";
    }
    cout << ']' << endl;
    return 0;
}