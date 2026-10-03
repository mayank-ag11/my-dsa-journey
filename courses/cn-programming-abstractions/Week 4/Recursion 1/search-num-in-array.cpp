// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
bool checkNumber(int input[], int n, int x) {
    if(n == 0)
        return false;
    if(input[0] == x)
        return true;
    
    return checkNumber(input+1, n-1, x);
}