// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
int countZeros(int n) {
	if(n == 0)
        return 1;
    if(n < 10)
        return 0;
    
    return ((n % 10 == 0) ? 1 : 0) + countZeros(n/10);
}