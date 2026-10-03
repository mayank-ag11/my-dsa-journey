/***
 * A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
 * Implement a method to count and return all possible ways in which the child can run-up to the stairs.
 ***/
// DP - O(n)
long staircase(int n)
{
	long *ways = new long[n + 1];
    ways[0] = 1, ways[1] = 1, ways[2] = 2;
    
    for(int i = 3; i <= n; i++)
        ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
    
    return ways[n];
}

// Brute Force - O(3^n)
long staircase(int n){
    if(n == 0 || n == 1)
        return 1;
    
    if(n == 2)
        return 2;
    
    return staircase(n-1) + staircase(n-2) + staircase(n-3);
}