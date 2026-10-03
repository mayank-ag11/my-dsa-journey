#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void stack_operations() {
    Stack* stack = NULL;
    int size = 0;

    while(1) {
	int q;
	scanf("%d", &q);

	if(q > 0) {
	    push(&stack, q);
	    size++;
	}
	else {
	    switch(q) {
		case 0:
		    if(is_stack_empty(stack))
			printf("E ");
		    else
			printf("NE ");
		    break;

		case -1:
		    q = pop(&stack);
		    if(q == -1)
			printf("E ");
		    else {
			printf("%d ", q);
			size--;
		    }
		    break;

		case -2:
		    // Always print NF as it's linked list implementation
		    printf("NF ");
		    break;

		case -3:
		    printf("%d ", size);
		    break;

		default: return;
	    }
	}
    }
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

int dequeue(Queue* q) {
    if(is_queue_empty(q)) {
	printf("E ");
	return -1;
    }

    struct QNode* temp = q->front;

    q->front = q->front->next;

    if(q->front == NULL)
	q->rear = NULL;

    int popped =  temp->data;
    free(temp);
    return popped;
}

int front(Queue* q) {
    return q->front->data;
}

void queue_operations() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = NULL;

    while(1) {
	int n;
	scanf("%d", &n);

	if(n > 0) {
	    enqueue(q, n);
	}
	else {
	    switch(n) {
		case 0:
		    if(is_queue_empty(q))
			printf("E ");
		    else
			printf("NE ");
		    break;

		case -1:
		    n = dequeue(q);
		    if(n != -1)
			printf("%d ", n);
		    break;

		case -2:
		    // Always print NF as linked list implementation
		    printf("NF ");
		    break;

		case -3:
		    printf("%ld ", q->front - q->rear);
		    break;

		default: return;
	    }
	}
    }
}

struct CharStack {
    int top;
    unsigned capacity;
    char** array;
};

struct CharStack* createStack(unsigned capacity) {
    struct CharStack* stack = (struct CharStack*) malloc(sizeof(struct CharStack));
    if(!stack)
	return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (char**) malloc (sizeof(char*) * capacity);

    for(int i=0; i<capacity; i++) {
	stack->array[i] = (char*) malloc(sizeof(char) * 5);
    }

    return stack;
}

int isEmpty(struct CharStack* stack) {
    return stack->top == -1;
}

void pushChar(struct CharStack* stack, char* op) {
    if(stack->top == stack->capacity - 1) {
	printf("F ");
        return;
    }
    stack->array[++stack->top] = op;
}

char* peekChar(struct CharStack* stack) {
    return stack->array[stack->top];
}

char* popChar(struct CharStack* stack) {
    if(!isEmpty(stack))
	return stack->array[stack->top--];
    return NULL;
}

int isOperand(char* ch) {
    for(int i=0; i<strlen(ch); i++)
	if(isdigit(ch[i]) == 0)
	    return 0;
    return 1;
}

int prec(char* ch) {
    if(strlen(ch) == 1) {
	if(ch[0] == '*' || ch[0] == '/' || ch[0] == '%')
	    return 8;
	else if(ch[0] == '+' || ch[0] == '-')
	    return 7;
	else if(ch[0] == '<' || ch[0] == '>')
	    return 5;
	else if(ch[0] == '&')
	    return 3;
	else if(ch[0] == '^')
	    return 2;
	else if(ch[0] == '|')
	    return 1;
    }
    else if(strlen(ch) == 2) {
	if((ch[0] == '<' && ch[1] == '<') || (ch[0] == '>' && ch[1] == '>'))
	    return 6;
	else if((ch[0] == '<' || ch[0] == '>') && ch[1] == '=')
	    return 5;
	else if((ch[0] == '=' || ch[0] == '!') && ch[1] == '=')
	    return 4;
    }
    return 0;
}

int isOperator(char* ch) {
    if(prec(ch) != 0)
	return 1;
    return 0;
}

char** infixToPostfix(int capacity, int* size) {
    struct CharStack* stack = createStack(capacity);
    char** res = (char**) malloc(sizeof(char*)*62);

    int i = 0, k = -1;

    res[0] = (char*) malloc(sizeof(char)*5);
    scanf("%s", res[0]);

    while(res[i][0] != '#') {
	if(i%2 == 0) { // operands at even indexes
	    if(!isOperand(res[i])) {
		printf("Error");
		return NULL;
	    }
	    res[++k] = res[i];
	}
	else { // operators at odd indexes
	    if(!isOperator(res[i])) {
		printf("Error");
		return NULL;
	    }

	    while(!isEmpty(stack) && prec(res[i]) <= prec(peekChar(stack))) {
		res[++k] = popChar(stack);
	    }

	    pushChar(stack, res[i]);
	}

	res[++i] = (char*) malloc(sizeof(char)*5);
	scanf("%s", res[i]);
    }

    while(!isEmpty(stack))
	res[++k] = popChar(stack);

    *size = k + 1;
    return res;
}

void infix_to_postfix(int capacity) {
    int size = 0;
    char **res = infixToPostfix(capacity, &size);
    int i = 0;

    if(res == NULL)
	return;

    while(i < size) {
	printf("%s ", res[i]);
	i++;
    }
}

int countDigits(int n) {
    int ctr = 0;
    while(n) {
	ctr++;
	n /= 10;
    }
    return ctr;
}

char* calculate(char* sign, char* op1, char* op2) {
    int a = atoi(op1);
    int b = atoi(op2);
    int c;

    if(strlen(sign) == 1) {
	switch(sign[0]) {
	    case '*':
		c = a * b; break;
	    case '/':
		c = a / b; break;
	    case '%':
		c = a % b; break;
	    case '+':
		c = a + b; break;
	    case '-':
		c = a - b; break;
	    case '<':
		c = a < b; break;
	    case '>':
		c = a > b; break;
	    case '&':
		c = a & b; break;
	    case '^':
		c = a ^ b; break;
	    case '|':
		c = a | b; break;
	    default: c = 0;
	}
    }
    else if(strlen(sign) == 2) {
	if(sign[0] == '<')
	    if(sign[1] == '<')
	        c = a << b;
	    else if(sign[1] == '=')
		c = a <= b;

	else if(sign[0] == '>')
	    if(sign[1] == '>')
	        c = a >> b;
	    else if(sign[1] == '=')
		c = a >= b;

	else if(sign[0] == '=' && sign[1] == '=')
	    c = a == b ;

	else if(sign[0] == '!' && sign[1] == '=')
	    c = a != b;
    }

    char* res = (char*) malloc(sizeof(char)*countDigits(c));
    sprintf(res, "%d", c);
    return res;
}

void evaluate_infix(int capacity) {
    int size = 0;
    char **exp = infixToPostfix(capacity, &size); // exp is postfix expression

    if(exp == NULL)
	return;

    struct CharStack* stack = createStack(capacity);

    for(int i=0; i<size; i++) {
	if(isOperand(exp[i]))
	    pushChar(stack, exp[i]);
	else if(isOperator(exp[i])) {
	    char* op2 = popChar(stack);
	    char* op1 = popChar(stack);

	    char* res = calculate(exp[i], op1, op2);
	    pushChar(stack, res);
	}
    }

    printf("%s", peekChar(stack));
}

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

void findKthStackPermutation(int n, int k) {
    int x = 1;
    int* arr;
    for(int i=1; i<=k;) {
	arr = findKthPermutation(n, x);
	x++;
	if(is_stack_permutation(n, arr))
	    i++;
    }
    display(arr, n);
}

void stack_permutation() {
    int n, k;
    scanf("%d %d", &n, &k);

    int total_permutations = catalan(n);
    printf("%d ", total_permutations);

    findKthStackPermutation(n, k);
}

int main() {
    int t, k;
    scanf("%d %d", &t, &k);

    while(t--) {
	char ch;
	scanf("\n%c", &ch);

	switch(ch) {
	    case 'S' : stack_operations();  printf("\n");  break;
	    case 'Q' : queue_operations();  printf("\n");  break;
	    case 'I' : infix_to_postfix(k); printf("\n");  break;
	    case 'E' : evaluate_infix(k);   printf("\n");  break;
	    case 'P' : stack_permutation(); printf("\n");  break;
	    default: t++;
	}
    }
}
