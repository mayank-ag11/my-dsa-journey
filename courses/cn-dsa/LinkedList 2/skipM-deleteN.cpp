/***
 * You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
 * To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
 * Test case:
        10 22 10 26 11 7 8 1 23 5 1 28 0
        M = 2, N = 3
        => 10 22 7 8 1 28
 ***/
// Based on Java Solution
Node *skipMdeleteN(Node *head, int M, int N) {
    if(M == 0 or head == NULL)
        return NULL;
    if(N == 0)
        return head;
    
    Node *curr = head, *temp = new Node(-1);
    while(curr != NULL) {
        int take = 0, skip = 0;
        while(curr != NULL and take < M) {
            temp->next = curr;
            temp = curr;
            curr = curr->next;
            take++;
        }
        while(curr != NULL and skip < N) {
            Node *t = curr;
            curr = curr->next;
            delete t;
            skip++;
        }
    }
    
    if(temp != NULL)
        temp->next = NULL;
    return head;
}

// First Try
Node *skipMdeleteN(Node *head, int M, int N) {
	Node *curr = new Node(-1);
    Node *newHead = curr;
    curr->next = head;
    int m = M, n = N;
    bool del = false;
    
    while(curr != NULL and curr->next != NULL) {
        if(del) {
            while(curr != NULL and curr->next != NULL and n--) {
                Node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            del = false;
            n = N;
        }
        else {
            while(curr != NULL and m--)
                curr = curr->next;
            del = true;
            m = M;
        }
    }
    return newHead->next;
}