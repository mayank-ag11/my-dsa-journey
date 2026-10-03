/***
 * You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
 * Print only the integer part of the median.
 * Read this: https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
 ***/
// Better Way
#include <queue>
void findMedian(int *arr, int n) {
    if(n == 0)
        return;
    
    // lowerHalf -> Max-Heap, upperHalf -> Min-Heap
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> upperHalf;
    
    for(int i = 1; i <= n; i++) {
        // Adding elements
        if(!lowerHalf.empty() and lowerHalf.top() > arr[i - 1]) {
            lowerHalf.push(arr[i - 1]);
            if(lowerHalf.size() > upperHalf.size() + 1) {
                upperHalf.push(lowerHalf.top());
                lowerHalf.pop();
            }
        }
        else {
            upperHalf.push(arr[i - 1]);
            if(upperHalf.size() > lowerHalf.size() + 1) {
                lowerHalf.push(upperHalf.top());
                upperHalf.pop();
            }
        }

        // Finding median
        int median;
        if(i % 2 == 1) {
            if(upperHalf.size() > lowerHalf.size())
                median = upperHalf.top();
            else
                median = lowerHalf.top();
        }
        else {
            median = (lowerHalf.top() + upperHalf.top()) / 2;
        }
        cout << median << ' ';
    }
}

// First Try
#include <queue>
void findMedian(int *arr, int n) {
    if(n == 0)
        return;
    
    // MaxHeap -> lower half, MinHeap -> upper half
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(arr[0]);
    cout << arr[0] << ' ';
    
    for(int i = 1; i < n; i++) {
        int median;
        if(maxHeap.size() == minHeap.size()) {
            if(!maxHeap.empty() and arr[i] <= maxHeap.top()) {
                maxHeap.push(arr[i]);
                median = maxHeap.top();
            }
            else {
                minHeap.push(arr[i]);
                median = minHeap.top();
            }
        }
        else {
            if(minHeap.size() > maxHeap.size()) {
                if(arr[i] <= minHeap.top())
                    maxHeap.push(arr[i]);
                else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }
            else {
                if(arr[i] >= maxHeap.top())
                    minHeap.push(arr[i]);
                else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(arr[i]);
                }
            }
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        cout << median << ' ';
    }
}