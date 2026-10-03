/***
 * An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
 * From a cell (i, j), you can move in three directions:
    1. ((i + 1),  j) which is, "down"
    2. (i, (j + 1)) which is, "to the right"
    3. ((i+1), (j+1)) which is, "to the diagonal"
 * The cost of a path is defined as the sum of each cell's values through which the route passes.
 ***/

// DP - T: O(m*n), S: O(m*n)
int minCostPath(int **input, int m, int n) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
    }

    // Fill the last cell (destination)
    output[m-1][n-1] = input[m-1][n-1];

    // Fill the last row (right to left)
    for(int j = n - 2; j >= 0; j--) {
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }

    // Fill the last column (bottom to top)
    for(int i = m - 2; i >= 0; i--) {
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

    // Fill the remaining cells
    for(int i = m - 2; i >= 0; i--) {
        for(int j = n - 2; j >= 0; j--) {
            output[i][j] = min(output[i][j+1], min(output[i+1][j+1], output[i+1][j])) + input[i][j];
        }
    }

    return output[0][0];
}

// Memoization - T: O(m*n), S: O(m*n)
#include<climits>
int minCostPath(int **input, int m, int n, int i, int j, int **output) {
    if(i >= m or j >= n)
        return INT_MAX;

    if(i == m - 1 and j == n - 1)
        return input[i][j];

    if(output[i][j] != -1)
        return output[i][j];
    
    int downCost = minCostPath(input, m, n, i + 1, j, output);
    int rightCost = minCostPath(input, m, n, i, j + 1, output);
    int diagonalCost = minCostPath(input, m, n, i + 1, j + 1, output);
    
    output[i][j] = input[i][j] + min({downCost, rightCost, diagonalCost});
    return output[i][j];
}
int minCostPath(int **input, int m, int n) {
    // int dp[101][101];
    // memset(dp, -1, sizeof(dp));

    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
	return minCostPath(input, m, n, 0, 0, output);
}

// Recursive - O(3^n)
#include<climits>
int minCostPath(int **input, int m, int n, int i, int j) {
    if(i >= m or j >= n)
        return INT_MAX;
    
    if(i == m - 1 and j == n - 1)
        return input[i][j];
    
    int downCost = minCostPath(input, m, n, i + 1, j);
    int rightCost = minCostPath(input, m, n, i, j + 1);
    int diagonalCost = minCostPath(input, m, n, i + 1, j + 1);
    
    return input[i][j] + min({downCost, rightCost, diagonalCost});
}
int minCostPath(int **input, int m, int n) {
	return minCostPath(input, m, n, 0, 0);
}