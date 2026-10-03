#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coef, power;
    struct Node *next;
};

//Function to add a new node at the end of the list
void push(struct Node **head, int c, int p) {
    //Create a new node
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->coef = c;
    new->power = p;
    new->next = NULL;

    //if linked list is empty
    if (*head == NULL)
    {
       *head = new;
       return;
    }
    //if linked list has nodes
    struct Node *curr = *head;
    while (curr->next)
       curr = curr->next;

    curr->next = new;
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* resPoly = NULL;
    while(p1 && p2) {
	if(p1->power == p2->power) {
	    push(&resPoly, p1->coef+p2->coef, p1->power);
	    p1 = p1->next;
	    p2 = p2->next;
	}
	else if(p1->power > p2->power) {
	    push(&resPoly, p1->coef, p1->power);
	    p1 = p1->next;
	}
	else {
	    push(&resPoly, p2->coef, p2->power);
	    p2 = p2->next;
	}
    }

    if(p1) {
	while(p1) {
	    push(&resPoly, p1->coef, p1->power);
	    p1 = p1->next;
	}
    }

    if(p2) {
	while(p2) {
	    push(&resPoly, p2->coef, p2->power);
	    p2 = p2->next;
	}
    }

    return resPoly;
}

struct Node* subPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* resPoly = NULL;
    while(p1 && p2) {
        if(p1->power == p2->power) {
	    int coef = p1->coef-p2->coef;
	    if(coef)
               push(&resPoly, p1->coef-p2->coef, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->power > p2->power) {
            push(&resPoly, p1->coef, p1->power);
            p1 = p1->next;
        }
        else {
            push(&resPoly, -(p2->coef), p2->power);
            p2 = p2->next;
        }
    }

    if(p1) {
        while(p1) {
            push(&resPoly, p1->coef, p1->power);
            p1 = p1->next;
        }
    }

    if(p2) {
        while(p2) {
            push(&resPoly, -(p2->coef), p2->power);
            p2 = p2->next;
        }
    }

    return resPoly;
}

int evaluatePolynomial(struct Node* curr, int x) {
    int res = 0;
    while(curr) {
	res += (curr->coef * pow(x, curr->power));
	curr = curr->next;
    }
    return res;
}

void printPolynomial(struct Node* head) {
    if(head == NULL) {
	printf("0\n");
	return;
    }

    struct Node* curr = head;
    if(curr->coef < 0)
	printf("- ");
    while(curr->next) {
	printf("%dx^%d", abs(curr->coef), curr->power);
	curr = curr->next;
	if(curr->coef > 0)
	    printf(" + ");
	else
	    printf(" - ");
    }

    if(curr->power == 0)
	printf("%d\n", abs(curr->coef));
    else
	printf("%dx^%d\n", abs(curr->coef), curr->power);
}

struct Node* scanPolynomial() {
    int power, coef;
    struct Node *poly = NULL;

    scanf("%d", &power);
    while(power >= 0) {
        scanf("%d", &coef);
        if(coef != 0)
            push(&poly, coef, power);
        power--;
    }
    return poly;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
	struct Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL, *poly4 = NULL;

	// Initialization of polynomials
	poly1 = scanPolynomial();
	poly2 = scanPolynomial();
	int x;
	scanf("%d", &x);

	printf("P1(x) : ");
	printPolynomial(poly1);

	printf("P2(x) : ");
	printPolynomial(poly2);

	// Operations on polynomials
	poly3 = addPolynomials(poly1, poly2);
	printf("P3(x) = P1(x) + P2(x) : ");
	printPolynomial(poly3);

	poly4 = subPolynomials(poly1, poly2);
	printf("P4(x) = P1(x) - P2(x) : ");
	printPolynomial(poly4);
	
	// Evaluation of polynomials
	int p1 = evaluatePolynomial(poly1, x);
	printf("P1(%d) = %d\n", x, p1);

	int p2 = evaluatePolynomial(poly2, x);
	printf("P2(%d) = %d\n", x, p2);

	printf("P3(%d) = %d\n", x, p1+p2);
	printf("P4(%d) = %d", x, p1-p2);
	if(t != 0)
	    printf("\n");
    }
}
