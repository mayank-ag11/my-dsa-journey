/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here
    int ctr=1;
    Node *temp=head;
    Node *prev;
    if(x==1)
      {
          head=head->next;
	  free(temp);
          return head;
      }
    while(ctr!=x)
    {
        prev=temp;
        temp=temp->next;
        ctr++;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}
