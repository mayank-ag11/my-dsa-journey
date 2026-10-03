int multiplyNumbers(int m, int n) {
    if(n == 0)
        return 0;
    if(m < n)
        return multiplyNumbers(n, m);
    
    return m + multiplyNumbers(m, n-1);
}