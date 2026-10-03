/***
 * You are given an array of n elements and a sum value, you have to calculate the total number of ways to calculate the given sum using the elements of the array by using only addition(+) and subtraction operator(-).
 ***/
int number(int *arr, int n, int sum, int i, int curr_sum) {
    if(i >= n) {
        if(sum == curr_sum)
            return 1;
        else
            return 0;
    }
    
    return number(arr, n, sum, i+1, curr_sum) +
           number(arr, n, sum, i+1, curr_sum + arr[i]) +
           number(arr, n, sum, i+1, curr_sum - arr[i]);
}

int number(int* input,int n,int sum)
{
    int res = number(input, n, sum, 0, 0);
    if(sum == 0)
        res--;
    return res;
}