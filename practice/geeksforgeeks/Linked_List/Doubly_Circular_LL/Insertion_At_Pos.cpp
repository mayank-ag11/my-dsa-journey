/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

/* Function to insert into a Doubly Linked List */
//Own Try
void addNode(Node *head, int pos, int data)
{
   Node *curr=head,*prev=NULL;
   int ctr=0;
   while(curr)
   {
       if(ctr==pos+1)
       {
           Node *newnode = new Node(data);
           newnode->next=curr;
           newnode->prev=prev;
           prev->next=newnode;
           curr->prev=newnode;
           break;
       }
       ctr++;
       prev=curr;
       curr=curr->next;
   }
   if(ctr==pos+1)
   {
      Node *newnode = new Node(data);
      newnode->next=curr;
      newnode->prev=prev;
      prev->next=newnode;
   }
}
//From GfG
void addNode(Node *head, int pos, int data)
{
   Node* newNode = new Node(data);
   Node* curr = head;
   while(curr != NULL && pos--){
    curr = curr->next;
   }
   if(curr->next == NULL) {
      curr->next = newNode;
      newNode->prev = curr;
      newNode->next = NULL;
   }
   else{
      Node* store_next = curr->next;
      newNode->prev = curr;
      newNode->next = store_next;
      curr->next = newNode;
      store_next->prev = newNode;
   }
}
