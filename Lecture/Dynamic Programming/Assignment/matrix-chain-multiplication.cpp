/***
 * Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices.
 * In other words, determine where to place parentheses to minimize the number of multiplications.
 * 
 * You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i].
 * You need to find minimum number of multiplications needed to multiply the chain.
 * Test Case:
    n = 3, arr = [10 15 20 25]
    => 8000
 * Explanation:
    There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
    If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
    If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
    Thus, minimum number of multiplications required are 8000.
 * 
 * Go through the notes or the hint video to understand. 
***/

// DP - T: O(n^3), S: O(n^2)
#include<climits>
int matrixChainMultiplication(int* arr, int n) {
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[n + 1];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = i + 2; j <= n; j++) {
            int min = INT_MAX;
            for(int k = i + 1; k <= j - 1; k++) {
                int currAns = dp[i][k] + dp[k][j] +
                                (arr[i] * arr[k] * arr[j]);
                if(currAns < min)
                    min = currAns;
            }

            dp[i][j] = min;
        }
    }
    return dp[0][n];
}

// Memoization - T: O(n^2 * n), S: O(n^2)
#include<climits>
int matrixChainMultiplication(int* arr, int s, int e, int **dp) {
    // If zero or one matrix only
    if(s >= e - 1) return 0;

    // Check if the ans already exists
    if(dp[s][e] != -1) return dp[s][e];

    int min = INT_MAX;
    // (Ms+1 to Mk) * (Mk to Me)
    for(int k = s + 1; k <= e - 1; k++) {
        // Check the hint video or notes for the formula
        int currAns = matrixChainMultiplication(arr, s, k, dp) +
                      matrixChainMultiplication(arr, k, e, dp) +
                      (arr[s] * arr[k] * arr[e]);

        if(min > currAns)
            min = currAns;
    }

    // Add the ans to dp
    dp[s][e] = min;
    return min;
}
int matrixChainMultiplication(int* arr, int n) {
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
    }
    return matrixChainMultiplication(arr, 0, n, dp);
}

// Brute Force - T: O(n^n+1), S: O(n)
#include<climits>
int matrixChainMultiplication(int* arr, int s, int e) {
    // if zero or one matrix only
    if(s >= e - 1) return 0;

    int min = INT_MAX;
    // (Ms+1 to Mk) * (Mk to Me)
    for(int k = s + 1; k <= e - 1; k++) {
        // Check the hint video or notes for the formula
        int currAns = matrixChainMultiplication(arr, s, k) +
                      matrixChainMultiplication(arr, k, e) +
                      (arr[s] * arr[k] * arr[e]);

        if(min > currAns)
            min = currAns;
    }
    return min;
}
int matrixChainMultiplication(int* arr, int n) {
    return matrixChainMultiplication(arr, 0, n);
}

/*
Time complexity: O(N^3)
Space complexity: O(N^2)
where N is the number of matrices to multiply
*/
public class Solution {
    public static int mcm(int[] p) {
        int storage[][] = new int[p.length][p.length];
        for (int i = p.length - 2; i >= 1; i--) {
            for (int j = 1; j <= p.length - 1; j++) {
                if (i < j) {
                    int minCost = Integer.MAX_VALUE;
                    for (int k = i; k < j; k++) {
                        int cost = storage[i][k] + storage[k + 1][j] +
                            p[i - 1] * p[k] * p[j];
                        if (cost < minCost) {
                            minCost = cost;
                        }
                        storage[i][j] = minCost;
                    }
                }
            }
        }
        return storage[1][p.length - 1];
    }
}