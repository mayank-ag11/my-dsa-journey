/*
Time complexity: O(N * M)
Space compleity: O(N * M)
where N and M are the lengths of the two input strings
*/
public class ShortestSubsequence {
    static int INF = 1000000000;
    int[][] dp;
    int[][] next;
    public int solve(String S, String V) {
        /*
        We establish the relationship between the sub problems and the problem
        at hand.
        Let dp(i, j) be the length of the shortest subsequence that is in
        S[1..i]
        that is not in V[1..j]. Here we have the following relationship:
        dp(i, j) =
        1. If letter S[i] is nowhere to be found in V[1..j], then dp(i,j) = 1.
        2. Otherwise, we have two case:
        2.1. S[i] is in the shortest subsequence. We find k, the most
        immediate index in V[1..j]
        where V[k] == S[i]. Then dp(i, j) = 1 + dp(i-1, k-1).
        2.2 S[i] is not in the shortest subsequence. Then dp(i, j) = dp(i1, j).
        We pick whichever is lower.
        */
        int n = S.length(), m = V.length(), i, j, prev;
        dp = new int[n + 1][m + 1];
        next = new int[n + 1][m + 1];
        for (i = 0; i < n; i++) {
            prev = -1;
            for (j = 0; j < m; j++) {
                if (S.charAt(i) == V.charAt(j))
                    prev = j;
                next[i + 1][j + 1] = prev;
            }
        }
        for (i = 1; i <= n; i++)
            dp[i][0] = 1;
        for (i = 0; i <= m; i++) {
            dp[0][i] = INF;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (next[i][j] == -1)
                    dp[i][j] = 1;
                else {
                    dp[i][j] = Math.min(dp[i - 1][j], 1 + dp[i - 1][next[i]
                        [j]
                    ]);
                }
            }
        }
        return dp[n][m];
    }
}