#include<stdio.h>
#include<stdlib.h>

int findFirstIndex(int* k, int n) {
    if(n == 1)
	return 0;
    n--;

    int index;
    int n_partial_fact = n;

    while(*k >= n_partial_fact && n > 1) {
	n_partial_fact = n_partial_fact * (n - 1);
	n--;
    }

    index = *k / n_partial_fact;

    *k = *k % n_partial_fact;

    return index;
}

void delete(int* arr, int n, int pos) {
    for(int i = pos; i < n - 1; i++) {
	arr[i] = arr[i+1];
    }
}

int* findKthPermutation(int n, int k) {
    int* res = (int*) malloc(sizeof(int)*n);

    int arr[n];
    for(int i=0; i<n; i++) {
	arr[i] = i+1;
    }

    k--;

    for(int i=0; i<n;  i++) {
	int index = findFirstIndex(&k, n - i);

	res[i] = arr[index];

	delete(arr, n - i, index);
    }

    return res;
}

void display(int* arr, int n) {
    for(int i=0; i<n; i++) {
	printf("%d ", arr[i]);
    }
    // printf("\n");
}

// Using dynamic programming
int catalan(int n) {
    int cat[n+1];

    cat[0] = cat[1] = 1;

    for(int i=2; i<=n; i++) {
	cat[i] = 0;
	for(int j=0; j<i; j++)
	    cat[i] += cat[j] * cat[i-j-1];
    }
    return cat[n];
}

struct QNode {
    int data;
    struct QNode* next;
};

typedef struct Queue {
    struct QNode *front, *rear;
} Queue;

int is_queue_empty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int k) {
    struct QNode* temp = (struct QNode*) malloc(sizeof(struct QNode));
    temp->data = k;
    temp->next = NULL;

    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(Queue* q) {
    if(is_queue_empty(q)) {
        printf("E ");
        return;
    }

    struct QNode* temp = q->front;

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    // printf("%d ", temp->data);
    free(temp);
}

int front(Queue* q) {
    return q->front->data;
}

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

int is_stack_empty(Stack* root) {
    return !root;
}

void push(Stack** root, int x) {
    Stack* new_node = (Stack*)malloc(sizeof(Stack));
    new_node->data = x;
    new_node->next = *root;
    *root = new_node;
}

int pop(Stack** root) {
    if(is_stack_empty(*root))
        return -1;

    Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int top(Stack* root) {
    return root->data;
}

int is_stack_permutation(int n, int*arr) {
    Queue* q1 = (Queue*) malloc(sizeof(Queue));
    q1->front = q1->rear = NULL;

    Queue* q2 = (Queue*) malloc(sizeof(Queue));
    q2->front = q2->rear = NULL;

    for(int i=0; i<n; i++) {
	enqueue(q1, i+1);
	enqueue(q2, arr[i]);
    }

    Stack* stack = NULL;

    while(!is_queue_empty(q1)) {
	int ele = front(q1);
	dequeue(q1);

	if(ele == front(q2)) {
	    dequeue(q2);
	    while(!is_stack_empty(stack)) {
		if(top(stack) == front(q2)) {
		    pop(&stack);
		    dequeue(q2);
		}
		else
		    break;
	    }
	}
	else
	    push(&stack, ele);
    }

    return (is_queue_empty(q1)) && (is_stack_empty(stack));
}

void testStackPermutations(int n, int k) {
    int x = 1, y = 1;

    for(int i=1; i<=24; i++) {
	int* arr = findKthPermutation(n, i);
	if(is_stack_permutation(n, arr)) {
	    printf("%dSP ", x);
	    x++;
	}
	display(arr, n);
	printf("%dP\n", y++);
    }
}	

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    /*int* arr = findKthPermutation(n, k);

    int total_permutations = catalan(n);

    printf("%d ", total_permutations);
    if(is_stack_permutation(n, arr))
        display(arr, n);
    */

    testStackPermutations(n, k);
}
