// C implementation of the above approach
#include <stdio.h>
#include <stdlib.h>
// Node Structure containing powerer
// and coefficient of variable
struct Node{
    int coef;
    int power;
    struct Node *next;
};

//Function to add a new node at the end of the list
void push(struct Node **head, int c, int p)
{
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

//Function to add coefficients of
//two elements having same powerer
int addTerms(struct Node **head, int c, int p)
{
   int check = 0; //to check if similar terms were found or not
   struct Node *curr = *head;
   while (curr)
   {
      //if powerer of an element = the new power
      if (curr->power == p)
      {
	//add the new coeff to the coefficient of the element
	curr->coef += c;
	check = 1;
      }
      curr = curr->next;
   }
   return check;
}
		   
//Function to multiply two polynomials
void Multiply(struct Node *p1, struct Node *p2, struct Node **p3)
{
    //Storing addresses of 1st and 2nd polynomials
    struct Node *h1 = p1, *h2 = p2;
    struct Node *h3 = *p3;

    //k=0 so that addTerms is not called for 1st Traversal
    int k = 0;

    while (h1)
    {
       h2 = p2;
       while (h2)
       {
	  int new_c, new_p;
	  //Multiply coefficients of both
	  //polynomials and store it in new_c
	  new_c = h1->coef * h2->coef;

	  //Add the powerer of both polynomials
	  //and store it in new_p
          new_p = h1->power + h2->power;

	  //if similar terms exist, add them
	  if (k == 1)
            k = addTerms(p3, new_c, new_p);

	  //if similar terms don't exist, create new node
	  if (k == 0)
            push(p3, new_c, new_p);

	  //move the pointer of 2nd polynomial to its next term
	  h2 = h2->next;
       }
       //start to call addTerms after the 1st traversal of h1
       k = 1;
       //move the pointer of 1st polynomial to its next term
       h1 = h1->next;
    }
}

//Function to display the linked list
void printList(struct Node *head)
{
    struct Node *curr=head;
    while (curr->next)
    {
       printf("%dx^%d + ", curr->coef, curr->power);
       curr = curr->next;
    }
    printf("%d\n", curr->coef);
}

//Driver Code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

    //Creation of 1st polynomial: 3x^2 + 5x^1 + 6
    push(&poly1, 3,2);
    push(&poly1, 5,1);
    push(&poly1, 6,0);
    //Creation of 2nd polynomial: 6x^1 + 8
    push(&poly2, 6,1);
    push(&poly2, 8,0);

    //Displaying 1st polynomial
    printf("1st Polynomial:- ");
    printList(poly1);

    //Displaying 2nd polynomial
    printf("2nd Polynomial:- ");
    printList(poly2);

    //Multiplying the polynomials
    Multiply(poly1, poly2,&poly3);

    //Displaying the Resultant polynomial
    printf("Resultant Polynomial:- ");
    printList(poly3);
}
