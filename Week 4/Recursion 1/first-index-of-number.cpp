/***
 * Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
 * First index means, the index of first occurrence of x in the input array.
 ***/
int firstIndex(int input[], int n, int x) {
    if(n == 0)
        return -1;
    if(input[0] == x)
        return 0;
    
    int ans = firstIndex(input+1, n-1, x);
    if(ans != -1)
        ans++;
    return ans;
}