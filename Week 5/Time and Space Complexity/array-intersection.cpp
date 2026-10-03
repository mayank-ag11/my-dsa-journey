/***
 * You have been given two integer arrays/list(ARR1 and ARR2) of size M and N, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
 * Constraints: 
 * Input arrays/lists can contain duplicate elements.
 * The intersection elements printed would be in the order they appear in the first array/list(ARR1)
 * Sample Testcase:
 * (2 6 8 5 4 3), (2 3 4 7) --> 2 4 3
 * (10 10), (10) --> 10
 * (2 6 1 2), (1 2 3 4 2) --> 2 1 2
 * Articles Read:
 * https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
 ***/

/*
Time Complexity : O((n * log(n)) + (m * log(m)))
Space Complexity : O(1)
A more optimized solution to this problem is possible
using HashMaps which will have:
Time Complexity: O(n + m)
Space Complexity : O(min(n, m))
where 'n' and 'm' are sizes of the input arrays/lists
*/
void intersection(int *arr1, int *arr2, int n, int m) {
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    int i = 0; //Pointer to iterate over arr1
    int j = 0; //Pointer to iterate over arr2
    while(i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}

// Brute Force - O(n^2)
#include<climits>
#include<iostream>
using namespace std;

void intersection(int *input1, int *input2, int size1, int size2)
{
    for(int i=0; i<size1; i++) {
        for(int j=0; j<size2; j++) {
            if(input1[i] == input2[j]) {
                cout << input1[i] << ' ';
                input2[j] = INT_MIN;
                break;
            }
        }
    }
}

/*
#include<algorithm>
void intersection(int *input1, int *input2, int size1, int size2)
{
    // Sorting 2nd array
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    
    // BinarySearch every element of first array in 2nd array
    for(int i=0; i<n; i++) {
        int index = lower_bound(arr2, arr2 + m, arr1[i]) - arr2;
        if(arr2[index] == arr1[i]) {
            cout << arr1[i] << ' ';
            arr2[index] = -1;
            // sort(arr2, arr2 + m);
        }
    }
}*/