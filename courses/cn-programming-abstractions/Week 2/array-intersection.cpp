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

// Brute Force
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
// Didn't work because of order constraint
#include<algorithm>
void intersection(int *input1, int *input2, int size1, int size2)
{
    // Sorting 2nd array
    sort(input2, input2 + size2);
    
    // BinarySearch every element of first array in 2nd array
    for(int i=0; i<size1; i++) {
        int index = lower_bound(input2, input2 + size2, input1[i]) - input2;
        if(input2[index] == input1[i]) {
            cout << input1[i] << ' ';
            input2[index] = -1;
        }
    }
}*/