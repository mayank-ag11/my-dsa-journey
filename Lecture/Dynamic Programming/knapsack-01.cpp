/***
 * A thief robbing a store can carry a maximal weight of W into his knapsack.
 * There are N items, and i-th item weigh 'Wi' and the value being 'Vi.'
 * What would be the maximum value V, that the thief can steal?
 ***/

/*
Time complexity: O(N * W)
Space complexity: O(W)
where N is the number of items
and W is the maximum weight that the theif can carry
*/
#include <vector>

int knapsack(int * weight, int * value, int n, int maxWeight) {
    vector < vector < int >> dp(2, vector < int > (maxWeight + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= maxWeight; ++j) {
            if (weight[i] <= j) {
                dp[i % 2][j] = max(value[i] + dp[(1 + i) % 2][j - weight[i]], dp[(i + 1) %
                    2][j]);
            } else {
                dp[i % 2][j] = dp[(i + 1) % 2][j];
            }
        }
    }
    return dp[(n + 1) % 2][maxWeight];
}

// Optimized space complexity by reusing the same rows again and again
// DP - T: O(n * W), S: O(W)
int knapsack(int *weights, int *values, int n, int maxWeight) {
    int **dp = new int*[2];
    for(int i = 0; i < 2; i++) {
        dp[i] = new int[maxWeight + 1];
    }

    // Filling the last row (dp[1])
    for(int w = 0; w <= maxWeight; w++)
        dp[1][w] = 0;

    // First cell of first row (dp[0])
    dp[0][0] = 0;

    // dp[0][w] -> curr row, dp[1][w] -> prev row
    for(int i = n - 1; i >= 0; i--) {
        for(int w = 1; w <= maxWeight; w++) {
            if(weights[i] > w) {
                dp[0][w] = dp[1][w];
            }
            else {
                int includeItem = dp[1][w - weights[i]] + values[i];
                int excludeItem = dp[1][w];

                dp[0][w] = max(includeItem, excludeItem);
            }
        }
        for(int w = 0; w <= maxWeight; w++)
            dp[1][w] = dp[0][w];
    }

    return dp[0][maxWeight];
}

// DP - T: O(n * W), S: O(n * W)
int knapsack(int *weights, int *values, int n, int maxWeight) {
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[maxWeight + 1];
    }

    // Filling the last row
    for(int w = 0; w <= maxWeight; w++)
        dp[n][w] = 0;

    // Filling the first col
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    // Filling the rest
    for(int i = n - 1; i >= 0; i--) {
        for(int w = 1; w <= maxWeight; w++) {
            if(weights[i] > w) {
                dp[i][w] = dp[i + 1][w];
            }
            else {
                int includeItem = dp[i + 1][w - weights[i]] + values[i];
                int excludeItem = dp[i + 1][w];

                dp[i][w] = max(includeItem, excludeItem);
            }
        }
    }

    return dp[0][maxWeight];
}

// Memoization - T: O(n * W), S: O(n * W)
int knapsack(int *weights, int *values, int n, int maxWeight, int **dp) {
    if(n == 0 or maxWeight == 0)
        return 0;
    
    if(dp[n][maxWeight] != -1)
        return dp[n][maxWeight];

    if(weights[0] > maxWeight)
        return knapsack(weights + 1, values + 1, n - 1, maxWeight, dp);
    
    // Recursive Calls
    int includeItem = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], dp);
    int excludeItem = knapsack(weights + 1, values + 1, n - 1, maxWeight, dp);
    
    dp[n][maxWeight] = max(excludeItem, includeItem);
    return dp[n][maxWeight];
}

int knapsack(int *weights, int *values, int n, int maxWeight) {
  int **dp = new int*[n + 1];
  for(int i = 0; i <= n; i++) {
      dp[i] = new int[maxWeight + 1];
      for(int j = 0; j <= maxWeight; j++)
        dp[i][j] = -1;
  }

  return knapsack(weights, values, n, maxWeight, dp);
}

// Recursive - O(2^n)
int knapsack(int *weights, int *values, int n, int maxWeight) {
    if(n == 0 or maxWeight == 0)
        return 0;
    
    if(weights[0] > maxWeight)
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    
    // Recursive Calls
    int includeItem = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
    int excludeItem = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    
    return max(excludeItem, includeItem);
}

// First Try
int knapsack(int *weights, int *values, int n, int maxWeight) {
    if(n == 0 or maxWeight == 0)
        return 0;
    
    int excludeItem = knapsack(weights, values, n - 1, maxWeight);
    int includeItem = 0;
    if(maxWeight >= weights[n - 1])
        includeItem = values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1]);
    
    return max(excludeItem, includeItem);
}

// Java
/*
Time complexity: O(N * W)
Space complexity: O(W)
where N is the number of items
and W is the maximum weight that the theif can carry
*/
public class Solution {
    static int knapsack(int[] weight, int[] value, int n, int maxWeight) {
        int[][] dp = new int[2][maxWeight + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= maxWeight; ++j) {
                if (weight[i] <= j) {
                    dp[i % 2][j] = Math.max(value[i] + dp[(1 + i) % 2][j - weight[i]],
                        dp[(i + 1) % 2][j]);
                } else {
                    dp[i % 2][j] = dp[(i + 1) % 2][j];
                }
            }
        }
        return dp[(n + 1) % 2][maxWeight];
    }
}

/*
Time Complexity : O(3 ^ n)
Space Complexity : O(N)
Where N is the total number of weights
*/
public class Solution {
    public static int knapsack(int[] weights, int[] values, int n, int maxWeight) {
        if (n == 0 || maxWeight == 0) {
            return 0;
        }
        if (weights[n - 1] > maxWeight) {
            return knapsack(weights, values, n - 1, maxWeight);
        }
        int includeItem = values[n - 1] + knapsack(weights, values, n - 1, maxWeight -
            weights[n - 1]);
        int excludeItem = knapsack(weights, values, n - 1, maxWeight);
        return Math.max(includeItem, excludeItem);
    }
}