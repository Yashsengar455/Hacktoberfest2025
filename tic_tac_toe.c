#include <stdio.h>
#include <stdlib.h>

/*
===========================================
        TIC TAC TOE GAME IN C
===========================================

👾 Description:
A simple console-based Tic Tac Toe game for two players.
Players take turns marking X and O on a 3x3 grid.
The first player to align three marks horizontally, vertically, or diagonally wins.

💡 Concepts used:
- 2D arrays
- Loops and conditionals
- Functions and modular programming
- Input validation
*/

void printBoard(char board[3][3]);   // Function to display the board
int checkWin(char board[3][3]);      // Function to check if a player has won
int isFull(char board[3][3]);        // Function to check for a draw

int main() {
    // Initialize the 3x3 board with numbers 1–9
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int player = 1;   // Player 1 starts first
    char mark;        // X or O
    int choice;       // Player's move (1–9)
    int row, col;     // Coordinates on the board
    int result = 0;   // Used to store win/draw status

    printf("=== TIC TAC TOE ===\n");
    printf("Player 1: X | Player 2: O\n\n");

    // Game continues until someone wins or board fills up
    while (1) {
        printBoard(board);

        // Determine which player's turn it is
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d, enter a position (1-9): ", player);
        scanf("%d", &choice);

        // Validate input
        if (choice < 1 || choice > 9) {
            printf("Invalid move! Choose a number between 1 and 9.\n");
            continue;
        }

        // Convert position (1–9) to board indices
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the chosen cell is already taken
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("That spot is already taken! Try again.\n");
            continue;
        }

        // Place the player's mark on the board
        board[row][col] = mark;

        // Check if current player has won
        result = checkWin(board);
        if (result == 1) {
            printBoard(board);
            printf("\n🎉 Player %d wins the game!\n", player);
            break;
        }

        // Check if the board is full (draw)
        if (isFull(board)) {
            printBoard(board);
            printf("\nIt's a draw! 🤝\n");
            break;
        }

        // Switch player turn
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

/*
-------------------------------------------
Function: printBoard
-------------------------------------------
Displays the current state of the 3x3 board
-------------------------------------------
*/
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

/*
-------------------------------------------
Function: checkWin
-------------------------------------------
Checks all possible winning conditions:
- 3 in a row
- 3 in a column
- 3 diagonally
Returns 1 if a player has won, 0 otherwise.
-------------------------------------------
*/
int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

/*
-------------------------------------------
Function: isFull
-------------------------------------------
Checks if all positions on the board are filled.
Returns 1 if full (draw), 0 otherwise.
-------------------------------------------
*/
int isFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}
