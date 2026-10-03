/***
 * Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
 ***/
bool isMaxHeap(int arr[], int n) {
    // in max-heap, parent >= children
    int parentIndex = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    
    while(leftChildIndex < n) {
        if(arr[leftChildIndex] > arr[parentIndex])
            return false;
        if(rightChildIndex < n and arr[rightChildIndex] > arr[parentIndex])
            return false;
        
        parentIndex++;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = leftChildIndex + 1;
    }
    
    return true;
}

// Java
/*
Time complexity: O(N)
Space complexity: O(1)
where N is the size of the input array
*/
public class Solution {
    public static boolean checkMaxHeap(int arr[]) {
        int n = arr.length;
        for (int i = 0; 2 * i + 1 < n; i++) {
            int leftChildIndex = 2 * i + 1;
            int rightChildIndex = leftChildIndex + 1;
            // if left child greater than parent then return false
            if (arr[i] < arr[leftChildIndex]) {
                return false;
            }
            // if right child exists and is greater than parent then return false
            if (rightChildIndex < n && arr[i] < arr[rightChildIndex]) {
                return false;
            }
        }
        return true;
    }
}