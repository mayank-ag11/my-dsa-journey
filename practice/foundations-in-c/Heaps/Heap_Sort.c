#include<stdio.h>
#include<stdlib.h>

struct maxHeap {
    int size;
    unsigned capacity;
    int* array;
};

struct maxHeap* createHeap(unsigned capacity) {
    struct maxHeap* heap = (struct maxHeap*) malloc(sizeof(struct maxHeap));

    if(!heap)
        return NULL;

    heap->size = 0;
    heap->capacity = capacity;

    heap->array = (int*) malloc(sizeof(int)*capacity);

    return heap;
}

void insert(struct maxHeap* heap, int x) {
    if(heap->size == heap->capacity) {
        printf("Heap Full!");
        return;
    }

    heap->array[heap->size] = x;

    // percolate up
    int currIndex = heap->size;

    while(currIndex > 0) {
        int parentIndex = (currIndex - 1) / 2;
        if(heap->array[currIndex] > heap->array[parentIndex]) {
            int temp = heap->array[currIndex];
            heap->array[currIndex] = heap->array[parentIndex];
            heap->array[parentIndex] = temp;
        }
        else
            break;

        currIndex = parentIndex;
    }

    heap->size += 1;
}

void percolate_down(struct maxHeap* heap, int currIndex) {
    int child1 = 2 * currIndex + 1;
    int child2 = 2 * currIndex + 2;

    while(child2 < heap->size) {
	if(heap->array[child1] > heap->array[child2]) {
	    if(heap->array[child1] > heap->array[currIndex]) {
		int x = heap->array[child1];
		heap->array[child1] = heap->array[currIndex];
		heap->array[currIndex] = x;
		currIndex = child1;
	    }
	    else break;
	}
	else {
	    if(heap->array[child2] > heap->array[currIndex]) {
		int x = heap->array[child2];
		heap->array[child2] = heap->array[currIndex];
		heap->array[currIndex] = x;
		currIndex = child2;
	    }
	    else break;
	}
	child1 = 2 * currIndex + 1;
	child2 = 2 * currIndex + 2;
    }

    if(child1 < heap->size) {
	if(heap->array[child1] > heap->array[currIndex]) {
	    int x = heap->array[child1];
	    heap->array[child1] = heap->array[currIndex];
	    heap->array[currIndex] = x;
	}
    }
}

int delete(struct maxHeap* heap) {
    if(heap->size == 0)
        return -1;

    int temp = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    heap->array[heap->size-1] = temp;
    heap->size--;

    // percolate down
    percolate_down(heap, 0);

    return temp;
}

void display(struct maxHeap* heap) {
    for(int i=0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int* heapsort(int* arr, int n) {
    struct maxHeap* heap = createHeap(n);

    // n insertions
    for(int i=0; i<n; i++) {
	insert(heap, arr[i]);
    }

    // n deletions
    for(int i=0; i<n; i++) {
	delete(heap);
	// printf("%d ",delete(heap));
    }

    // copying to original array
    //for(int i=0; i<n; i++) {
//	arr[i] = heap->array[i];
  //  }
    return heap->array;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++) {
	scanf("%d", &arr[i]);
    }

    // heapsort(arr, n);
    int* sorted = heapsort(arr, n);

    for(int i=0; i<n; i++) {
	printf("%d ", sorted[i]);
    }
    printf("\n");
}
