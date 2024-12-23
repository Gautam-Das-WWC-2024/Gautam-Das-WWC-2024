#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char gameBoard[3][3]) {
    cout << "-------------" << endl;
    for (int row = 0; row < 3; row++) {
        cout << "| ";
        for (int col = 0; col < 3; col++) {
            cout << gameBoard[row][col] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if the current player has won
bool hasPlayerWon(char gameBoard[3][3], char currentPlayer) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((gameBoard[i][0] == currentPlayer && gameBoard[i][1] == currentPlayer && gameBoard[i][2] == currentPlayer) ||
            (gameBoard[0][i] == currentPlayer && gameBoard[1][i] == currentPlayer && gameBoard[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals for a win
    if ((gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer) ||
        (gameBoard[0][2] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

// Function to check if the game board is full (draw scenario)
bool isDraw(char gameBoard[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (gameBoard[row][col] == ' ') {
                return false; // Empty space found, game still ongoing
            }
        }
    }
    return true; // No empty spaces, it's a draw
}

int main() {
    // Initialize the game board with empty spaces
    char gameBoard[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    int chosenRow, chosenCol;

    // Game loop
    while (true) {
        displayBoard(gameBoard);
        cout << "Player " << currentPlayer << ", it's your turn!" << endl;
        cout << "Enter row (0-2): ";
        cin >> chosenRow;
        cout << "Enter column (0-2): ";
        cin >> chosenCol;

        // Validate the player's move
        if (chosenRow < 0 || chosenRow > 2 || chosenCol < 0 || chosenCol > 2 || gameBoard[chosenRow][chosenCol] != ' ') {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }

        // Update the board with the current player's move
        gameBoard[chosenRow][chosenCol] = currentPlayer;

        // Check if the current player has won
        if (hasPlayerWon(gameBoard, currentPlayer)) {
            displayBoard(gameBoard);
            cout << "Congratulations! Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the game ends in a draw
        if (isDraw(gameBoard)) {
            displayBoard(gameBoard);
            cout << "It's a draw! Well played both!" << endl;
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
