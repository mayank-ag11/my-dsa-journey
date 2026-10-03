#include <stdio.h>
#include <stdlib.h>
int k,ori;
typedef struct Node{
    int data;
    struct Node *next;
} Node;

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
void deleteNodes(Node **head)
{
    Node *temp;
    while((*head)->data<(*head)->next->data&&k!=0)
    {
       temp=*head;
       *head=(*head)->next;
       k--;
       free(temp);
    }
    if(k!=0)
    {
       Node *curr=*head;
       while(curr->next->next!=NULL&&k!=0)
       {
	  if(curr->next->data<curr->next->next->data)
	  {
             temp=curr->next;
	     curr->next=curr->next->next;
	     free(temp);
	     k--;
	  }
	  else curr=curr->next;
       }
    }
    if(k==ori)
    {
       while(k--)
       {
	  Node *curr=*head;
	  while(curr->next->next!=NULL)
            curr=curr->next;

	  temp=curr->next;
	  curr->next=NULL;
	  free(temp);
       }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
       int n;
       scanf("%d %d", &n, &k);
       ori=k;
       Node *head=NULL;
       while(n--)
       {
          int x;
          scanf("%d", &x);
          push(&head, x);
       }
       
       while(k!=0)
       {
          deleteNodes(&head);
	  ori=k;
       }
       printList(head);
    }
}
