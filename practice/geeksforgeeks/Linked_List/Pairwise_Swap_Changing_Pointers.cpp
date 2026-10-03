/* This program swaps the nodes of linked list 
rather than swapping the field from the nodes. 
Imagine a case where a node contains many 
fields, there will be plenty of unnecessary 
swap calls. */
#include<bits/stdc++.h> 
using namespace std; 

/* A linked list node */
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

/* Function to pairwise swap elements of a 
linked list */
Node *pairWiseSwap(Node *head) 
{
    // If linked list is empty or there is only 
    // one node in list 
    if (head == NULL || head->next == NULL) 
        return head; 
  
    // Fix the head and its next explicitly to 
    // avoid many if else in while loop 
    Node *curr = head->next->next; 
    Node *prev = head; 
    head = head->next; 
    head->next = prev; 
  
    // Fix remaining nodes 
    while (curr != NULL && curr->next != NULL) 
    { 
        prev->next = curr->next; 
        prev = curr; 
        Node *next = curr->next->next; 
        curr->next->next = curr; 
        curr = next; 
    } 
      
    prev->next = curr; 
  
    return head; 
}  

/* Function to add a node at the beginning of 
Linked List */
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Function to print nodes in a given linked list */
void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

/* Function to delete the entire linked list */
void deleteList(struct Node** head_ref)
{
   /* deref head_ref to get the real head */
   struct Node* current = *head_ref;
   struct Node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}
/* Druver program to test above function */
int main() 
{ 
	struct Node *start = NULL; 

	/* The constructed linked list is: 
	1->2->2->4->5->6->7->8 */
	push(&start, 8); 
	push(&start, 7); 
	push(&start, 6); 
	push(&start, 5); 
	push(&start, 4); 
	push(&start, 2); 
	push(&start, 2); 
        push(&start, 1);

	printf("\nLinked list before calling pairWiseSwap():"); 
	printList(start); 

	start = pairWiseSwap(start); 

	printf("\nLinked list after calling pairWiseSwap():"); 
	printList(start); 
        deleteList(&start);
	return 0; 
} 
