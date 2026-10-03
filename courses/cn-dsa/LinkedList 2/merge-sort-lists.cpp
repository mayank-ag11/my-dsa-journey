Node *merge(Node *head1, Node *head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    Node *newHead = NULL, *newTail = NULL;
    if(head1->data <= head2->data) {
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    }
    else {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }
    
    while(head1 != NULL and head2 != NULL) {
        if(head1->data <= head2->data) {
            newTail->next = head1;
            newTail = newTail->next;
            head1 = head1->next;
        }
        else {
            newTail->next = head2;
            newTail = newTail->next;
            head2 = head2->next;
        }
    }
    
    if(head1 != NULL)
        newTail->next = head1;
    
    if(head2 != NULL)
        newTail->next = head2;
    
    return newHead;
}
Node *mergeSort(Node *head)
{
    if(head == NULL or head->next == NULL)
        return head;
    
	Node *fast = head->next, *slow = head;
    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node *head2 = slow->next;
    Node *head1 = head;
    slow->next = NULL;
    
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return merge(head1, head2);
}