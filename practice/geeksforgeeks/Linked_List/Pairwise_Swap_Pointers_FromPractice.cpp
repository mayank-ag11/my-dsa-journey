/*struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

Node* pairWiseSwap(struct Node* head) 
{
    if(head==NULL||head->next==NULL)
      return head;
    struct Node *prev, *curr;
    prev=head;
    curr=head->next;
    head=curr;
    
    while(1)
    {
        struct Node *temp=curr->next;
        curr->next=prev;
        if(!temp||!(temp->next))
        {
            prev->next=temp;
            break;
        }
        prev->next=temp->next;
        prev=temp;
        curr=prev->next;
    }
    return head;
}
