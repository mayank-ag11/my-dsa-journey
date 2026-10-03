/***
 * For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
 ***/
Node *evenAfterOdd(Node *head) {
    if(head == NULL)
        return head;
    
	Node *odd = new Node(-1), *even = new Node(-1);
    Node *o = odd, *e = even;
    Node *curr = head;
    while(curr != NULL) {
        Node *temp = curr->next;
        if(curr->data % 2 == 0) {
            even->next = curr;
            even = even->next;
        }
        else {
            odd->next = curr;
            odd = odd->next;
        }
        curr = temp;
    }
    
    o = o->next;
    e = e->next;
    
    if(o == NULL)
        return e;
    
    odd->next = e;
    even->next = NULL;
    return o;
}