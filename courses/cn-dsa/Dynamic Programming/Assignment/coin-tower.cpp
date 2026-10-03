/***
 * Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns.
 * Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower.
 * The person to make the last move wins the game. Can you find out who wins the game?
 * 
 * Test Case:
    a. n = 4, x = 2, y = 3
    ==> Whis
    b. n = 10, x = 2, y = 4
    ==> Beerus
 ***/

/*
Time complexity : O(n)
Space complextiy : O(n)
where n is the initial number of coins
*/
string findWinner(int n, int x, int y) {
    //We are assuming that y is greater than or equal to x
    if (x > y) {
        swap(x, y);
    }
    /*
    dp[i] represents whether Beerus will win provided that "i" coins
    are remaining and it is Beerus' turn.
    If Beerus will win in that scenario, dp[i] will be true otherwise
    it'll be false.
    */
    bool * dp = new bool[n + 1];
    // i represents number of remaining coins
    for (int i = 1; i <= n; ++i) {
        /*
        Trivial case : if 1, x or y coins are remaining and it's Beerus' turn,
        he will simply pick up all coins and win the game.
        */
        if (i == 1 || i == x || i == y) {
            dp[i] = true;
        }
        /*
        If less than x coins remain, each player can only pick up one coin per
        turn.
        So the result of the game when i coins are remaining will be the reverse
        of the result when there were i - 1 coins.
        */
        else if (i < x) {
            dp[i] = !dp[i - 1];
        }
        /*
        If the number of coins is between x and y, each player can pick up either
        1 or x coins
        per turn. Now, each player wants to win, so they will look at the state of the
        game when
        i - 1 coins remain and also when i - x coins remain. If the player is winning
        in any of
        those states, he will try to get to that state, i.e, if the player is winning
        in i - 1
        state, he will remove 1 coin. If he's winning in the i - x state, he will
        remove i - x
        coins. If he is losing in both states, then it doesn't matter what he does, he
        will still
        lose.
        So to get the value of dp[i], we will first AND(&) the values of dp[i - 1] and
        dp[i - x]
        and then NOT(!) it.
        */
        else if (i < y) {
            dp[i] = !(dp[i - x] && dp[i - 1]);
        }
        /*
        The reasoning for this case is similar to the one explained above
        */
        else {
            dp[i] = !(dp[i - x] && dp[i - y] && dp[i - 1]);
        }
    }
    bool result = dp[n];
    delete[] dp;
    if (result) {
        return "Beerus";
    } else {
        return "Whis";
    }
}

// DP - T: O(n), S: O(n)
string findWinner(int n, int x, int y) {
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[2];
    }

    dp[0][0] = dp[1][0] = 0;
    dp[0][1] = dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int player = 0; player < 2; player++) {
            if(i == x || i == y) {
                dp[i][player] = player;
                continue;
            }
            
            int winner = !player;

            if(dp[i - 1][!player] == player)
                winner = player;
            if(i > x and dp[i - x][!player] == player)
                winner = player;
            if(i > y and dp[i - y][!player] == player)
                winner = player;

            dp[i][player] = winner;
        }
    }

    if(dp[n][0] == 0)
        return "Beerus";
    else
        return "Whis";
}

// Memoization - T: O(n), S: O(n)
int findWinner(int n, int x, int y, int player, int **dp) {
    if(n == 1 || n == x || n == y) return player;

    if(dp[player][n] != -1) return dp[player][n];

    int winner = !player;

    if(findWinner(n - 1, x, y, !player, dp) == player)
        winner = player;
    
    if(n > x and findWinner(n - x, x, y, !player, dp) == player)
        winner = player;
    
    if(n > y and findWinner(n - y, x, y, !player, dp) == player)
        winner = player;

    dp[player][n] = winner;
    return winner;
}

string findWinner(int n, int x, int y) {
    int **dp = new int*[2];
    for(int i = 0; i < 2; i++) {
        dp[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
    }
    if(findWinner(n, x, y, 0, dp) == 0)
        return "Beerus";
    else
        return "Whis";
}

// Brute Force - T: O(3^n), S: O(n)
int findWinner(int n, int x, int y, int player) {
    if(n == 1 || n == x || n == y) return player;

    if(findWinner(n - 1, x, y, !player) == player)
        return player;
    
    if(n > x and findWinner(n - x, x, y, !player) == player)
        return player;
    
    if(n > y and findWinner(n - y, x, y, !player) == player)
        return player;

    return !player;
}

string findWinner(int n, int x, int y) {
    if(findWinner(n, x, y, 0) == 0)
        return "Beerus";
    else
        return "Whis";
}