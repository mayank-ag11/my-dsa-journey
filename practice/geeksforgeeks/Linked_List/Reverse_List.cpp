// My Method (Iterative)
Node* reverseList(Node *head)
{
    struct Node *temp,*current,*prev;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        temp=current;
        current=current->next;
        temp->next=prev;
        prev=temp;
    }
    return temp;
}

// Recursive Approach
Node* reverseList(Node *head)
{
    if(head->next==NULL)
      return head;
      
    struct Node *newhead= reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
