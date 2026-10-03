/*struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to remove duplicates from the linked list
Node * removeDuplicates( Node *head) 
{
 if(head!=NULL&&head->next!=NULL)
 {
    struct Node *current,*temp,*temp2;
    current=head;
    while(current!=NULL&&current->next!=NULL)
    {
      int key=current->data;
      temp=current;
      while(temp->next!=NULL)
      {
        if(temp->next->data==key)
          {
            temp2=temp->next->next;
            free(temp->next);
            temp->next=temp2;
          }
        else
          temp=temp->next;
      }
      current=current->next;
    }
 }
 return head;
}
