#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char> >& board);
void displayBoard(const vector<vector<char> >& board);
bool checkWin(const vector<vector<char> >& board, char player);
bool checkDraw(const vector<vector<char> >& board);
bool isValidMove(const vector<vector<char> >& board, int row, int col);
void switchPlayer(char& currentPlayer);

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameFinished = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameFinished) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        if (isValidMove(board, row, col)) {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameFinished = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameFinished = true;
            } else {
                switchPlayer(currentPlayer);
            }
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (Y/N): ";
    cin >> playAgain;
    if (playAgain == 'Y' || playAgain == 'y') {
        main(); // Restart the game
    } else {
        cout << "Thank you for playing!" << endl;
    }

    return 0;
}

// Function definitions

void initializeBoard(vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char> >& board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char> >& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool isValidMove(const vector<vector<char> >& board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

