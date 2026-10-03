/***
 * Problem: Check if 2D Grid contains a string as path
 * Given a NxM matrix containing Uppercase English Alphabets only.
 * Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
 * There is a path from any cell to all its neighbouring cells.
 * For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
 * Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
 * 
 * Test Case:
    N = 2, M = 11
    CXDXNXNXNXA
    XOXIXGXIXJX

    => 1

    N = 4, M = 4
    CANI
    OOJN
    DDIG
    JNIN

    => 1
 ***/

// T: O(n * m), S: O(n * m)
bool explore(vector<vector<char>> &board, int n, int m, int r, int c, string target, bool **visited) {
    bool rowInbounds = 0 <= r and r < n;
    bool colInbounds = 0 <= c and c < m;
    if(!rowInbounds or !colInbounds) return false;

    if(target[0] != board[r][c]) return false;

    if(target.length() == 1) return true;

    if(visited[r][c]) return false;

    visited[r][c] = true;

    bool ans = false;
    int dXdY[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for(int i = 0; i < 8; i++) {
        int newR = r + dXdY[i][0];
        int newC = c + dXdY[i][1];

        ans = explore(board, n, m, newR, newC, target.substr(1), visited);
        if(ans) break;
    }
    /*
    bool ans = explore(board, n, m, r-1, c-1, target.substr(1), visited)
            or explore(board, n, m, r-1, c, target.substr(1), visited)
            or explore(board, n, m, r-1, c+1, target.substr(1), visited)
            or explore(board, n, m, r, c+1, target.substr(1), visited)
            or explore(board, n, m, r+1, c+1, target.substr(1), visited)
            or explore(board, n, m, r+1, c, target.substr(1), visited)
            or explore(board, n, m, r+1, c-1, target.substr(1), visited)
            or explore(board, n, m, r, c-1, target.substr(1), visited);
    */

    visited[r][c] = false;
    return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++)
        visited[i] = new bool[m]();

    string target = "CODINGNINJA";

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(board[r][c] == target[0] and explore(board, n, m, r, c, target, visited))
                return true;
        }
    }
    return false;
}

// Coding Ninjas Solution
/*
Time complexity: O(N * M)
Space complexity: O(N * M)
where N and M are the rows and columns respectively of the board
*/
int validPoint(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool dfs(vector < vector < char >> & board, vector < vector < bool >> & used, string & word, int x, int y, int wordIndex, int n, int m) {
    if (wordIndex == 11) {
        return true;
    }
    used[x][y] = true;
    bool found = false;
    int dXdY[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for (int i = 0; i < 8; ++i) {
        int newX = x + dXdY[i][0];
        int newY = y + dXdY[i][1];
        if (validPoint(newX, newY, n, m) && board[newX][newY] == word[wordIndex] &&
            !used[newX][newY]) {
            found = found | dfs(board, used, word, newX, newY, wordIndex + 1, n, m);
        }
    }
    used[x][y] = false;
    return found;
}
bool hasPath(vector < vector < char >> & board, int n, int m) {
    bool foundPath = false;
    string word = "CODINGNINJA";
    vector < vector < bool >> used(n, vector < bool > (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                foundPath = dfs(board, used, word, i, j, 1, n, m);
                if (foundPath) break;
            }
        }
        if (foundPath) break;
    }
    return foundPath;
}