#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct Node { 
    int data; 
    struct Node* next; 
}Node; 
  
// This function prints contents of linked list starting from 
// the given node 
void printList(Node* n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->next; 
    } 
} 
  
int main() 
{ 
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
  
    // allocate 3 nodes in the heap 
    head = (Node*)malloc(sizeof(Node)); 
    second = (Node*)malloc(sizeof(Node)); 
    third = (Node*)malloc(sizeof(Node)); 
  
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with second 
  
    second->data = 2; // assign data to second node 
    second->next = third; 
  
    third->data = 3; // assign data to third node 
    third->next = NULL; 
  
    printList(head); 
  
    return 0; 
}
