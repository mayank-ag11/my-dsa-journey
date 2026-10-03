/***
 * Given an array A and an integer K, print all subsets of A which sum to K.
 * 
 * Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
 * The order of subsets are not important. Just print them in different lines.
 ***/
void printSubsetSumToK(int arr[], int n, int output[], int oSize, int k) {
    if(n == 0) {
        if(k == 0) {
            for(int i=0; i<oSize; i++)
            	cout << output[i] << ' ';
        	cout << '\n';
        }
        return;
    }
    printSubsetSumToK(arr + 1, n - 1, output, oSize, k);
    
    int newArr[oSize + 1];
    int i = 0;
    for(; i < oSize; i++)
        newArr[i] = output[i];
    newArr[i] = arr[0];
    
    printSubsetSumToK(arr + 1, n - 1, newArr, oSize + 1, k-arr[0]);
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[0];
    printSubsetSumToK(input, size, output, 0, k);
}