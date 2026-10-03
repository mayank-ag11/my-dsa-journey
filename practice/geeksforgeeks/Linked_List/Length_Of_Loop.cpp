int countNodes(struct Node *n)
{
    int ctr=1;
    struct Node *temp=n->next;
    while(temp!=n)
      {
         ctr++;
         temp=temp->next;
      }
    return ctr;
}
int countNodesinLoop(struct Node *head)
{
    if(head==NULL) return 0;
    struct Node *slow,*fast;
    slow=fast=head;
    
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        {
           return countNodes(slow);
        }
    }
    return 0;
}
