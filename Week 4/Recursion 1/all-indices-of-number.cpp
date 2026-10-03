/***
 * Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
 ***/
int allIndexes(int input[], int n, int x, int output[]) {
    if(n == 0)
        return 0;
    
    int ans = allIndexes(input, n-1, x, output);

    if(input[n-1] == x) {
        output[ans++] = n-1;
    }
    return ans;
}