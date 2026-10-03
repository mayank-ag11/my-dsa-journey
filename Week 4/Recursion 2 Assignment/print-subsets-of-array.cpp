/***
 * Given an integer array (of length n), find and print all the subsets of input array.
 * 
 * Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
 * The order of subsets are not important. Just print the subsets in different lines.
 ***/
void printSubsetsOfArray(int arr[], int n, int output[], int oSize) {
    if(n == 0) {
        for(int i=0; i<oSize; i++)
            cout << output[i] << ' ';
        cout << '\n';
        return;
    }
    printSubsetsOfArray(arr + 1, n - 1, output, oSize);
    
    int newArr[oSize + 1];
    int i = 0;
    for(; i < oSize; i++)
        newArr[i] = output[i];
    newArr[i] = arr[0];
    
    printSubsetsOfArray(arr + 1, n - 1, newArr, oSize + 1);
}

void printSubsetsOfArray(int input[], int size) {
    int output[0];
    printSubsetsOfArray(input, size, output, 0);
}