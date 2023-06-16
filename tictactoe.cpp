#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if any player has won
bool checkWin(const vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i <= 2; ++i) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool checkFull(const vector<char>& board) {
    for (char c : board) {
        if (c == ' ')
            return false;
    }
    return true;
}

int main() {
    vector<char> board(9, ' ');
    int row, col;
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        drawBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Convert row and column to zero-based indexing
        --row;
        --col;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row * 3 + col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board with the current player's move
        board[row * 3 + col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        // Check if the game is a tie
        else if (checkFull(board)) {
            drawBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        }
        // Switch to the other player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
