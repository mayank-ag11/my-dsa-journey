#include<iostream>
using namespace std;
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    
    for(int j=l; j<=r-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int pivot_index = partition(arr, l, r);
        quickSort(arr, l, pivot_index-1);
        quickSort(arr, pivot_index+1, r);
    }
}

void quickSort(int input[], int size) {
	quickSort(input, 0, size-1);
}