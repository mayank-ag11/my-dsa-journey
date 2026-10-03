// Recursively
Node *reverseLinkedListRec(Node *head)
{
    if(head == NULL or head->next == NULL)
        return head;
    
    Node *smallHead = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

// Iteratively
Node *reverseLinkedList(Node *head)
{
    if(head == NULL)
        return head;

    Node *prev = NULL, *curr = head;
    while(curr != NULL) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    return prev;
}