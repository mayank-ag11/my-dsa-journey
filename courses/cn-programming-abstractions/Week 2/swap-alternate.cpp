/***
 * You have been given an array/list(ARR) of size N. You need to swap every pair of alternate elements in the array/list.
 * 
 * Sample 1: (n = 6) 9 3 6 12 4 32 --> 3 9 12 6 32 4
 * Sample 2: (n = 9) 9 3 6 12 4 32 5 11 19 --> 3 9 12 6 32 4 11 5 19
 ***/
void swapAlternate(int *arr, int n)
{
    if(n % 2 == 1)
        n--;
    
    for(int i=0; i<n; i+=2) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}