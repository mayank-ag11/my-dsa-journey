/***
 * You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
 * 
 * https://www.geeksforgeeks.org/array-rotation/
 ***/

// Juggling Algorithm
/*Function to get gcd of a and b*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}
void rotate(int *arr, int d, int n)
{
    if(d == 0 || n == 0)
        return;
    
    /* To handle if d >= n */
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
 
            if (k == i)
                break;
 
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

// Brute Force
/*void rotate(int *arr, int d, int n)
{
    while(d--) {
        int key = arr[0];
        
        for(int i=0; i < n-1; i++)
            arr[i] = arr[i+1];
        
        arr[n-1] = key;
    }
}*/