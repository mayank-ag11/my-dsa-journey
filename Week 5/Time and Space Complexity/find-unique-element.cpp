/***
 * You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
 * Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
 * You need to find and return that number which is unique in the array/list.
 * 
 * Articles Read:
 * https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
 * https://www.geeksforgeeks.org/find-unique-element-element-occurs-k-times-except-one/
 ***/
int findUnique(int *arr, int n)
{
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans ^= arr[i];
    }
    return ans;
}