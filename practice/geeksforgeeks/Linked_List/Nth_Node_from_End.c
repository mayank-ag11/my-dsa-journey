/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Method 1(Use two Pointers)
int getNthFromLast(Node *head, int n)
{
       struct Node *p=head;
       struct Node *f=head;

       for(int i=1;i<n;i++)
       {
         f=f->next;
	 if(f==NULL) return -1;
       }
       while(f->next!=NULL)
       {
         p=p->next;
	 f=f->next;
       }
       return p->data;
}

//Method 2(Use length of Linked List)
int length(Node *head)
{
    if(head==NULL) return 0;
    else return 1+length(head->next);
}
int getNthFromLast(Node *head, int n)
{
       int l=length(head);
       if(n>l) return -1;
       n=l-n+1;
       struct Node* temp=head;
       int ctr=0;
       while(temp!=NULL)
       {
           ctr++;
           if(ctr==n)
             return temp->data;
             
           temp=temp->next;
       }
       return -1;
}

