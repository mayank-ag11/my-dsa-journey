#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void push(struct Node *head, int x)
{
    struct Node *temp=head;
    while(temp->next!=NULL)
      temp=temp->next;
      
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=x;
    new->next=NULL;
    temp->next=new;
}
void pushfront(struct Node *head, int x)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=x;
    new->next=head;
    head=new;
}
void display(struct Node *head)
{
    struct Node *temp=head;
    while(temp)
      {
          printf("%d ", temp->data);
          temp=temp->next;
      }
}
int main()
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    head->data=5;
    head->next=NULL;
    pushfront(head, 8);
    pushfront(head, 10);
    pushfront(head, 11);
    display(head);
}
