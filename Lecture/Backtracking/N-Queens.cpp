/***
 * You are given N, and for a given N x N chessboard, find a way to place N queens,
 * such that no queen can attack any other queen on the chess board.
 * A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens.
 * You have to print all such configurations.
 * Note : Don't print anything if there isn't any valid configuration.
 * 
 * Test Case:
    N = 4
    =>  0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
        0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
 ***/

// T: O(n^n) or O(n!)
bool check(int **board, int row, int col, int n) {
    // Check above the current cell
    for(int i = row - 1; i >= 0; i--) {
        if(board[i][col] == 1)
            return false;
    }

    // Check diagonally left
    for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }

    // Check diagonally right
    for(int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++) {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

void placeQueens(int **board, int n, int row) {
    if(row == n) {
        // Valid Board Configuration
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cout << board[i][j] << ' ';
        cout << '\n';
        return;
    }

    // Check for all columns
    for(int col = 0; col < n; col++) {
        // Check if it's safe to place Queen
        if(row == 0 or check(board, row, col, n)) {
            // If it's safe -> then place the queen and move to next row
            board[row][col] = 1;
            placeQueens(board, n, row + 1);
            board[row][col] = 0;
        }
    }
}

void placeNQueens(int n) {
    int **board = new int*[n];
    for(int i = 0; i < n; i++)
        board[i] = new int[n]();

    placeQueens(board, n, 0);

    for(int i = 0; i < n; i++)
        delete[] board[i];
    delete[] board;
}
