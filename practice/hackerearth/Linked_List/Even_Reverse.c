#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;
void EvenReverse(Node **head)
{
    Node *first, *curr=*head;
    Node *temp, *prev=NULL;

    if((*head)->data%2==0)
    {
       first=*head;
       while(curr!=NULL&&curr->data%2==0)
         {
	    temp=curr;
	    curr=curr->next;
	    temp->next=prev;
	    prev=temp;
	 }
       first->next=curr;
       *head=prev;
    }
    while(curr!=NULL)
    {
       if(curr->data%2==0)
       {
	  first=prev;
          while(curr!=NULL&&curr->data%2==0)
	  {
	     temp=curr;
	     curr=curr->next;
	     temp->next=prev;
	     prev=temp;
	  }
	  first->next->next=curr;
	  first->next=prev;
       }
       else
       {
          prev=curr;
	  curr=curr->next;
       }
    }
}
void push(Node **head, int x)
{
    Node *new=(Node *)malloc(sizeof(Node));
    new->data=x;
    new->next=NULL;
    if(*head==NULL)
    {
       *head=new;
       return;
    }
    Node *curr=*head;
    while(curr->next!=NULL)
      curr=curr->next;
    curr->next=new;
}
void printList(Node *head)
{
    while(head!=NULL)
    {
       printf("%d ", head->data);
       head=head->next;
    }
    printf("\n");
}
void deleteList(Node** head_ref)
{
    Node* current = *head_ref;
    Node* next;

    while (current != NULL)
    {
       next = current->next;
       free(current);
       current = next;
    }

    *head_ref = NULL;
}
int main()
{
    int n;
    scanf("%d", &n);
    Node *head=NULL;
    while(n--)
    {
       int x;
       scanf("%d", &x);
       push(&head, x);
    }
    EvenReverse(&head);
    printList(head);
    deleteList(&head);
}
