/* C program for insertion sort on a linked list */
#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 
void sortedInsert(struct Node**, struct Node*);
void printList(struct Node *head);

void insertionSort(struct Node **head)
{
    int i=0;
    struct Node *sorted=NULL;
    struct Node *curr=*head;
    while(curr!=NULL)
    {
        struct Node *temp=curr->next;
        sortedInsert(&sorted, curr);
        curr=temp;
    }
    *head=sorted;
}
void sortedInsert(struct Node **head, struct Node* new_node)
{
    if(*head==NULL||(*head)->data>=new_node->data)
    {
        new_node->next=*head;
        *head=new_node;
    }
    else
    {
        struct Node *temp=*head;
        while(temp->next!=NULL&&temp->next->data<new_node->data)
           temp=temp->next;
        new_node->next=temp->next;
	temp->next=new_node;
    }
}
/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */

/* Function to print linked list */
void printList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while(temp != NULL) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = new Node; 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 


// Driver program to test above functions 
int main() 
{ 
	struct Node *a = NULL; 
	push(&a, 5); 
	push(&a, 20); 
	push(&a, 4); 
	push(&a, 3); 
	push(&a, 30); 

	printf("Linked List before sorting \n"); 
	printList(a); 

	insertionSort(&a); 

	printf("\nLinked List after sorting \n"); 
	printList(a); 

	return 0; 
} 
