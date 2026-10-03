/***
 * You have been given a random integer array/list(ARR) and a number X. Find and return the number of triplets in the array/list which sum to X.
 * Given array/list can contain duplicate elements.
 * 
 * Articles Read:
 * https://www.geeksforgeeks.org/print-all-triplets-with-given-sum/
 ***/
// Brute Force
int tripletSum(int *arr, int n, int x) {
    int ctr = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == x) {
                    ctr++;
                }
            }
        }
    }
    return ctr;
}

/*
// Not idle for this question
// Sorting and Two Pointer Technique
#include<algorithm>

int tripletSum(int *arr, int n, int x)
{
	if(n <= 2)
        return 0;
    
    sort(arr, arr+n);
    int ctr = 0;
    
    for(int i=0; i<n; i++){
             
    	if(i>0 && arr[i] == arr[i-1])  // avoid duplicate triplets count
        	continue;
             
        int num = arr[i];
        int target = x - num;
             
        for(int l=i+1, r=n-1; l<r; ) {
            if(arr[l] + arr[r] > target)                    
                r--;
                 
            else if (arr[l] + arr[r] < target)
                l++;
                 
            else {
                // arr[l] + arr[r] == target
                ctr++;
 
                // skip duplicates
                while( l<n-1 && arr[l] == arr[l+1]) l++;
                while( r>0 && arr[r] == arr[r-1]) r--;
                                             
                l++;
                r--;                   
                     
            }                
        }                                     
    }
    
    return ctr;
}*/