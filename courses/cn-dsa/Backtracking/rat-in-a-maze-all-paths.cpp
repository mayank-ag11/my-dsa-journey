/***
 * You are given a N*N maze with a rat placed at maze[0][0].
 * Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1].
 * Rat can move in any direc­tion ( left, right, up and down).
 * Value of every cell in the maze can either be 0 or 1.
 * Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
 * 
 * Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).

 * Test Case:
    N = 3
    1 0 1
    1 1 1
    1 1 1

    =>  1 0 0 1 1 1 1 1 1
        1 0 0 1 0 0 1 1 1
        1 0 0 1 1 0 0 1 1
        1 0 0 1 1 1 0 0 1
 ***/

// T: O(2^(n^2)), S: O(n^2)
void ratInAMaze(int maze[][20], int x, int y, int n, bool **path) {
    bool rowInbounds = 0 <= x and x < n;
    bool colInbounds = 0 <= y and y < n;
    if(!rowInbounds or !colInbounds) return;

    if(maze[x][y] == 0) return;

    if(path[x][y]) return;
    path[x][y] = true;

    // Printing the path
    if(x == n - 1 and y == n - 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << path[i][j] << ' ';
        }
        cout << '\n';
        path[x][y] = false;
        return;
    }

    // Top, Down, Left, Right
    int dXdY[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    for(int i = 0; i < 4; i++) {
        ratInAMaze(maze, x + dXdY[i][0], y + dXdY[i][1], n, path);
    }

    path[x][y] = false;
}

void ratInAMaze(int maze[][20], int n) {
    bool **path = new bool*[n];
    for(int i = 0; i < n; i++)
        path[i] = new bool[n]();

    ratInAMaze(maze, 0, 0, n, path);
    
    for(int i = 0; i < n; i++)
        delete[] path[i];
    delete[] path;
}

// Java Solution
/*
Time complexity : O(2^k)
Space complexity : O(N^2)
where N is the size of maze
and K is the numer of cells in maze with
value equal to one(1)
*/
import java.io.*;
import java.util.*;
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static void printsolution(int[][] solution, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(solution[i][j] + " ");
            }
        }
    }
    static void solveMaze(int maze[][], int solution[][], int x, int y, int n) {
        if (x == n - 1 && y == n - 1) {
            solution[x][y] = 1;
            printsolution(solution, n);
            System.out.println();
            return;
        }
        if (x > n - 1 || x < 0 || y > n - 1 || y < 0) {
            return;
        }
        if (maze[x][y] == 0 || solution[x][y] == 1) {
            return;
        }
        solution[x][y] = 1;
        solveMaze(maze, solution, x - 1, y, n);
        solveMaze(maze, solution, x + 1, y, n);
        solveMaze(maze, solution, x, y - 1, n);
        solveMaze(maze, solution, x, y + 1, n);
        solution[x][y] = 0;
    }
    static void ratInAMaze(int maze[][], int n) {
        int[][] solution = new int[20][20];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                solution[i][j] = 0;
            }
        }
        solveMaze(maze, solution, 0, 0, n);
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(br.readLine().trim());
        int[][] maze = new int[20][20];
        for (int i = 0; i < n; i++) {
            StringTokenizer tk = new StringTokenizer(br.readLine().trim());
            for (int j = 0; j < n; j++) {
                maze[i][j] = Integer.parseInt(tk.nextToken());
            }
        }
        ratInAMaze(maze, n);
    }
}