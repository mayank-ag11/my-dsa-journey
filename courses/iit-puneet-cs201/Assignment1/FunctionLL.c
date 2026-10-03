/*
 * Program to calculate n#
 * n# = (1^1) * (2^2) * (3^3) * ... * ((n-1)^(n-1)) * (n^n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int digit;
    struct Node* next;
};

void push(struct Node** head, int val) {
    // Create new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->digit = val;
    new_node->next = NULL;

    if(*head == NULL) {
	*head = new_node;
	return;
    }

    // Find last node
    struct Node* last = *head;
    while(last->next != NULL)
	last = last->next;

    // Insert at End
    last->next = new_node;
}

// Multiplies n with the number represented by res(linked list)
// Uses simple school mathematics for multiplication
void multiply(struct Node** res, int n) {
    int carry = 0;   // Initialize carry
    struct Node* curr = *res;

    // One by one multiply n with individual digits of res
    while(curr) {
	int prod = curr->digit * n + carry;

	// Store last digit of 'prod' in res
	curr->digit = prod % 10;

	// Put rest in carry
	carry = prod / 10;
	curr = curr->next;
    }

    // Put carry in res
    while(carry) {
	push(res, carry % 10);
	carry /= 10;
    }
}

// Calculates the n#
struct Node* calculate(int n) {
    // res to store the final result, initialized it with 1
    struct Node* res = NULL;
    push(&res, 1);

    // n# = (1^1) * (2^2) * (3^3) * ... * ((n-1)^(n-1)) * (n^n)
    while(n > 1) {
	for(int i=0; i<n; i++) {
	    multiply(&res, n);
	}
	n--;
    }
    return res;
}

// To reverse the linked list
struct Node* reverse(struct Node* head) {
    struct Node *temp, *curr, *prev;
    prev = NULL;
    curr = head;

    while(curr) {
	temp = curr;
	curr = curr->next;
	temp->next = prev;
	prev = temp;
    }
    return temp;
}

// Finds the no. of zeroes in list
int findZeroes(struct Node* head) {
    int ctr = 0;
    while(head) {
	if(head->digit != 0)
	    break;
	ctr++;
	head = head->next;
    }
    return ctr;
}

// Finds the no. of times pattern appears in the list
int checkPattern(struct Node* head, char* pattern) {
    int ctr = 0;
    int l = strlen(pattern);
    int match = 1;

    while(head) {
	int i;
	// if first digit matches
	if(head->digit == pattern[0] - '0') {
	    match = 1;
	    i = 0;
	    struct Node* curr = head;
	    while(curr && pattern[i] != '\0') {
		// if any digit doesn't match
		if(curr->digit != pattern[i] - '0') {
		    match = 0;
		    break;
		}
		curr = curr->next;
		i++;
	    }
	    // if match is true and i == length of pattern
	    if(match && i == l)
		ctr++;
	}
	head = head->next;
    }
    return ctr;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
	int n;
	char k[4];
	scanf("%d %s", &n, k);

	// Calculating n#
	struct Node* res = NULL;
	res = calculate(n);

	// Finding Zn i.e. no. of end zeroes in n#
	int no_of_zeroes = findZeroes(res);

	res = reverse(res);

	// Finding no. of times k pattern appears in n#
	int pattern_matches = checkPattern(res, k);

	printf("%d %d ", no_of_zeroes, pattern_matches);
	while(res) {
	    printf("%d", res->digit);
	    res = res->next;
	}
	if(t != 0)
	    printf("\n");
    }
}
