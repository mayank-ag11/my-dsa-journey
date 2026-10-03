/***
 * You are given an integer n and you have to print F(n)th term of the sequence if
 * F(n)=(1)+(2 * 3)+(4 * 5 * 6)+...n
 ***/
long Fnth_term(int cal, int cur, int n) {
    int i;
    long ans = 1;
    if(cur == n+1)
        return 0;
    
    for(i=cal; i<cal+cur; i++)
        ans *= i;
    
    return ans + Fnth_term(i, cur+1, n);
}

long Fnth_term(int n)
{
    Fnth_term(1, 1, n);
}

// Approach discussed in class (Webinar 16)
long Fnth_term(int n) {
    if(n <= 1)
        return n;
    
    int sum = n * (n+1) / 2;
    long prod = 1;
    for(int i=1; i<=n; i++) {
        prod *= sum;
        sum--;
    }
    
    long ans = Fnth_term(n-1);
    
    return ans + prod;
}