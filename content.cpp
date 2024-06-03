#include <bits/stdc++.h>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[]) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if the current player has won
bool checkWin(const char board[], char player) {
    // Check rows, columns, and diagonals
    return ((board[0] == player && board[1] == player && board[2] == player) ||
            (board[3] == player && board[4] == player && board[5] == player) ||
            (board[6] == player && board[7] == player && board[8] == player) ||
            (board[0] == player && board[3] == player && board[6] == player) ||
            (board[1] == player && board[4] == player && board[7] == player) ||
            (board[2] == player && board[5] == player && board[8] == player) ||
            (board[0] == player && board[4] == player && board[8] == player) ||
            (board[2] == player && board[4] == player && board[6] == player));
}

// Function to check if the board is full (draw)
bool checkDraw(const char board[]) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ')
            return false;
    }
    return true;
}

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Initialize the board

    char currentPlayer = 'O'; // Player O starts the game

    bool gameEnd = false;

    while (!gameEnd) {
        
        displayBoard(board); //invoking game board

        // Prompt the current player to enter their move
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Validate the move
        if (move >= 1 && move <= 9 && board[move - 1] == ' ') {
            // Update the board with the player's move
            board[move - 1] = currentPlayer;

            // Check for win
            if (checkWin(board, currentPlayer)) {
                
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnd = true;
            } else if (checkDraw(board)) {
                // Check for draw
                
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameEnd = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    return 0;
}
