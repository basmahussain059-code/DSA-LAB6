#include <iostream>
#include <iomanip>

using namespace std;

int N;
int board[20][20];

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N && board[r][c] == -1);
}

bool solveKnightTour(int row, int col, int moveNumber) {
    if (moveNumber > N * N) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];

        if (isValid(nextRow, nextCol)) {
            board[nextRow][nextCol] = moveNumber;
            
            if (solveKnightTour(nextRow, nextCol, moveNumber + 1)) {
                return true;
            }
            
            board[nextRow][nextCol] = -1;
        }
    }
    return false;
}

int main() {
    cout << "Enter board size N: ";
    cin >> N;
    
    int startRow, startCol;
    cout << "Enter starting row and column: ";
    cin >> startRow >> startCol;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    board[startRow][startCol] = 1;

    if (solveKnightTour(startRow, startCol, 2)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << setw(3) << board[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No tour found by the search.\n";
    }

    return 0;
}