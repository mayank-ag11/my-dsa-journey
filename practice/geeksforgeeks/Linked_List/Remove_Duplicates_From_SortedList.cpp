Node *removeDuplicates(Node *root)
{
    struct Node *temp;
    struct Node *current=root;
    if(current==NULL||current->next==NULL)
      return root;
      
    while(current->next!=NULL)
    {
        if(current->data==current->next->data)
        {
            //The sequence of steps is important
            temp=current->next->next;
            free(current->next);
            current->next=temp;
        }
        else
        {
            //only advance if no deletion
            current=current->next;
        }
    }
    return root;
}
