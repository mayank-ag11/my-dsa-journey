struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
//My Method
int length(Node *head,Node *temp)
{
    if(head->next==temp) return 0;
    else return 1+length(head->next,temp);
}
void splitList(Node *head, Node **head1, Node **head2)
{
    int i=0;
    int l=length(head,head)+1;
    int half=l/2+(l%2);
    
    *head1=head;
    struct Node *temp,*temp2;
    temp=*head1;
    while(--half)
      temp=temp->next;
      
    *head2=temp->next;
    temp->next=head;
    temp2=*head2;
    while(temp2->next!=head)
      temp2=temp2->next;
    temp2->next=*head2;
}
//Geeks Method
void splitList(Node *head, Node **head1, Node **head2)
{
    struct Node *slow, *fast;
    slow=fast=head;
    while(fast->next!=head&&fast->next->next!=head)
      {
          fast=fast->next->next;
          slow=slow->next;
      }
    if(fast->next->next==head)
      fast=fast->next;
      
    *head1=head;
    if(head->next!=head)
      *head2=slow->next;

    fast->next=slow->next;
    slow->next=head;
}
