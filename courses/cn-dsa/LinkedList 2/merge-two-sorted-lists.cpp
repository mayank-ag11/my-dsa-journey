/***
 * You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
 * Try solving this in O(1) auxiliary space.
 ***/
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    // if(head1 == NULL or head2 == NULL)
    //     return (head1 == NULL) ? head2 : head1;
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