#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>> &board);
void displayBoard(const vector<vector<char>> &board);
bool makeMove(vector<vector<char>> &board, char player, int row, int col);
bool checkWin(const vector<vector<char>> &board, char player);
bool checkDraw(const vector<vector<char>> &board);
bool playAgain();

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 game board
    char currentPlayer = 'X';
    bool gameInProgress = true;

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        initializeBoard(board);
        displayBoard(board);

        do {
            int row, col;

            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, currentPlayer, row, col)) {
                displayBoard(board);

                if (checkWin(board, currentPlayer)) {
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameInProgress = false;
                } else if (checkDraw(board)) {
                    cout << "It's a draw!\n";
                    gameInProgress = false;
                } else {
                    // Switch players
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }

        } while (gameInProgress);

    } while (playAgain());

    cout << "Thanks for playing!\n";

    return 0;
}

void initializeBoard(vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool makeMove(vector<vector<char>> &board, char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win
    }
    return false;
}

bool checkDraw(const vector<vector<char>> &board) {
    // Check if the board is full (draw)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full (draw)
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

