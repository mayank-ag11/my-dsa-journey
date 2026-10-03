/***
 * You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1. Write a function to sort this array/list. Think of a solution which scans the array/list only once and don't require use of an extra array/list.
 * 
 * Discussed 'Dutch National Flag Algorithm' in Class - 21st July, 2021
 * https://zoom.us/rec/share/JOeqkg3DiRD1-yAhO4e2f8jzh-5c4MbO0rF1iHmTmMPyxPT--OcvasgDIJFMp9Ae.aYBzzCcs_Z0z5G9q
 * https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
 ***/

// Method 1: Dutch National Flag Algo
void sortZeroesAndOne(int *input, int n)
{
	int low = 0, mid = 0;
    while(mid < n) {
        if(input[mid] == 0) {
            // swap(mid, low)
            int t = input[mid];
            input[mid] = input[low];
            input[low] = t;
            
            low++;
            mid++;
        }
        else   // input[mid] == 1
            mid++;
    }
}

// Method 2: Sum (Slightly faster)
void sortZeroesAndOne2(int *input, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += input[i];
    
    int j = n - sum;
    for(int i=0; i<j; i++)
        input[i] = 0;
    for(int i=j; i<n; i++)
        input[i] = 1;
}

// Method 3: One pointer
void sortZeroesAndOne3(int input[], int n) 
{ 
    int nextZero = 0; 
    for (int i = 0; i < n; i++) {
        if (input[i] == 0) {
            int temp = input[nextZero];
            input[nextZero] = input[i];
            input[i] = temp; nextZero++;
        } 
    } 
}