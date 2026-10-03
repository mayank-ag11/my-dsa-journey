// https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

// O(logn) algorithm
int power(int x, int n) {
    if( n == 0)
        return 1;

    int ans = power(x, n / 2);
    if (n % 2 == 0)
        return ans * ans;
    else
        return x * ans * ans;
}