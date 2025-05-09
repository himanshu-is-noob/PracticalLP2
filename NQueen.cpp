#include <iostream>
#include <vector>
using namespace std;

const int N = 4;
vector<int> board(N);
int solutionCount = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard() {
    cout << "Solution " << ++solutionCount << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << (board[i] == j ? "Q " : ". ");
        cout << endl;
    }
    cout << "-------------------\n";
}

void solveNQueens(int row) {
    if (row == N) {
        printBoard();
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1);
        }
    }
}

int main() {
    solveNQueens(0);
    if (solutionCount == 0) {
        cout << "No solutions found.\n";
    }
    return 0;
}
