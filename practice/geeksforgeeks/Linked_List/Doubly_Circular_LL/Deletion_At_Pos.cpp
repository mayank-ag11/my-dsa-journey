/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

// Function to delete the node at position x
void deleteNode(Node **head, int x)
{
    int ctr=0;
    struct Node *curr=(*head);
    if(x==1)
     {
        *head=curr->next;
        (*head)->prev=NULL;
        free(curr);
        return;
     }
    while(curr&&--x)
         curr=curr->next;
    if(curr->next==NULL)
      {
          curr->prev->next=NULL;
          free(curr);
          return;
      }
    else
      {
          curr->prev->next=curr->next;
          curr->next->prev=curr->prev;
          free(curr);
          return;
      }
}
