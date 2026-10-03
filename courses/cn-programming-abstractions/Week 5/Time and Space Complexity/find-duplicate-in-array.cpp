/***
 * You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3 and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
 * 
 * Articles Read:
 * https://medium.com/solvingalgo/solving-algorithmic-problems-find-a-duplicate-in-an-array-3d9edad5ad41
 * https://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-2/
 * https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
 ***/

// Method 1 : Sum (Faster Method)
int duplicateNumber(int *arr, int n)
{
    // Sum of numbers from 0 to (n - 2)
    int sum_n = 0;
    for(int i=1; i<n-1; i++)
    	sum_n += i;
    
    // Sum of array elements
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    return sum - sum_n;
}

// Method 2 : Use Array as HashMap
int duplicateNumber2(int *arr, int n)
{
    for(int i=0; i<n; i++) {
        int index = arr[i] % n;
        arr[index] += n;
        
        // arr[arr[i] % n] = arr[arr[i] % n] + n;
    }
    
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / n) >= 2)
            return i;
    }
    return -1;
}