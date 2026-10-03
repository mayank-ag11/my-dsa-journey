/***
 * Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
 * Note: Space complexity should be O(1).
 ***/
void insert(int pq[], int n, int element) {
    pq[n] = element;
    
    // up-heapify
    int childIndex = n;
	while(childIndex > 0) {
		int parentIndex = (childIndex - 1) / 2;

		if(pq[childIndex] < pq[parentIndex]) {
			int temp = pq[childIndex];
			pq[childIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		}
		else {
			break;
		}
		childIndex = parentIndex;
	}
}
void remove(int pq[], int n) {
    if(n == 0)
        return;
    
    int temp = pq[0];
    pq[0] = pq[n - 1];
    pq[n - 1] = temp;
    
    n--;
    // down-heapify
	int parentIndex = 0;
	int leftChildIndex = 1;
	int rightChildIndx = 2;
	
	while(leftChildIndex < n) {
		int minIndex = parentIndex;
		if(pq[minIndex] > pq[leftChildIndex]) {
			minIndex = leftChildIndex;
		}
		if(rightChildIndx < n && pq[rightChildIndx] < pq[minIndex]) {
			minIndex = rightChildIndx;
		}
		if(minIndex == parentIndex) {
			break;
		}
		int temp = pq[minIndex];
		pq[minIndex] = pq[parentIndex];
		pq[parentIndex] = temp;
		
		parentIndex = minIndex;
		leftChildIndex = 2 * parentIndex + 1;
		rightChildIndx = 2 * parentIndex + 2;
	}
}

void heapSort(int arr[], int n) {
    // Building Heap in-place
    for(int i = 1; i < n; i++)
        insert(arr, i, arr[i]);
    
    // Converting Heap into sorted array
    for(int i = 0; i < n; i++)
        remove(arr, n - i);
}

// Coding Ninjas Solution
#include <iostream>
using namespace std;

void inplaceHeapSort(int pq[], int n) {
    // Build the heap in input array
    for (int i = 1; i < n; i++) {

        int childIndex = i;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    // Remove elements
    int size = n;

    while (size > 1) {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndx = 2 * parentIndex + 2;

        while (leftChildIndex < size) {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex]) {
                minIndex = leftChildIndex;
            }
            if (rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
                minIndex = rightChildIndx;
            }
            if (minIndex == parentIndex) {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndx = 2 * parentIndex + 2;
        }
    }
}

int main() {
    int input[] = { 5, 1, 2, 0, 8 };
    inplaceHeapSort(input, 5);
    for (int i = 0; i < 5; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}