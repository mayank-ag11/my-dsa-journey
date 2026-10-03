/***
 * You are given a N*N maze with a rat placed at maze[0][0].
 * Find whether any path exist that rat can follow to reach its destination i.e. maze[N-1][N-1].
 * Rat can move in any direc­tion ( left, right, up and down).
 * Value of every cell in the maze can either be 0 or 1.
 * Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
 * 
 * Test Cases:
    a.  N = 3
        1 0 1
        1 0 1
        1 1 1

        => true

    b.  N = 3
        1 0 1
        1 0 1
        0 1 1

        => false
 ***/

// T: O(2^(n^2)), S: O(n^2)
bool ratInAMaze(int maze[][20], int x, int y, int n, bool **path) {
    bool rowInbounds = 0 <= x and x < n;
    bool colInbounds = 0 <= y and y < n;
    if(!rowInbounds or !colInbounds) return false;

    if(maze[x][y] == 0) return false;

    if(path[x][y]) return false;
    path[x][y] = true;

    if(x == n - 1 and y == n - 1) return true;

    // // If you want to print the path also
    // if(x == n - 1 and y == n - 1) {
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++)
    //             cout << path[i][j] << ' ';
    //         cout << '\n';
    //     }
    //     return true;
    // }

    // Top, Right, Down, Left
    int dXdY[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    for(int i = 0; i < 4; i++) {
        if(ratInAMaze(maze, x + dXdY[i][0], y + dXdY[i][1], n, path))
            return true;
    }

    path[x][y] = false;
    return false;
}

bool ratInAMaze(int maze[][20], int n) {
    bool **path = new bool*[n];
    for(int i = 0; i < n; i++)
        path[i] = new bool[n]();

    int ans = ratInAMaze(maze, 0, 0, n, path);
    
    for(int i = 0; i < n; i++)
        delete[] path[i];
    delete[] path;

    return ans;
}

// Java Solution
public class Solution {
	public static boolean ratInAMaze(int maze[][]){
        int n = maze.length;
        int path[][] = new int[n][n];
        return solveMaze(maze, 0, 0, path);
	}
    
    public static boolean solveMaze(int maze[][], int i, int j, int path[][]) {
        int n = maze.length;
        if(i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0 || path[i][j] == 1)
            return false;
        
        path[i][j] = 1;
        
        if(i == n - 1 && j == n - 1)
            return true;
        
        if(solveMaze(maze, i - 1, j, path))
            return true;
        if(solveMaze(maze, i, j + 1, path))
            return true;
        if(solveMaze(maze, i + 1, j, path))
            return true;
        if(solveMaze(maze, i, j - 1, path))
            return true;
        
        return false;
    }
}