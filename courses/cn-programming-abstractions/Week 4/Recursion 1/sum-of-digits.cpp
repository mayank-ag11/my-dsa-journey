// Write a recursive function that returns the sum of the digits of a given integer.
int sumOfDigits(int n) {
    if(n == 0)
        return 0;
    return n%10 + sumOfDigits(n/10);
}