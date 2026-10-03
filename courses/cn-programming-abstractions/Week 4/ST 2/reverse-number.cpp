// Find reverse of a number
// Recursive
int reverse(int n, int rev) {
    if(n == 0)
        return rev;

    rev = rev * 10 + n % 10;
    
    return reverse(n/10, rev);
}

int reverse(int n) {
    return reverse(n, 0);
}

// Iterative
int reverse(int n)
{
    int sum = 0;
    while(n) {
        int r = n % 10;
        sum = sum * 10 + r;
        n /= 10;
    }
    return sum;
}