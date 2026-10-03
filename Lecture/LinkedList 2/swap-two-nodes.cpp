/***
 * You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
 * Test Case:
   10 20 30 40, i = 1, j = 2
   => 10 30 20 40
 ***/
Node *swapNodes(Node *head, int i, int j) {
    if(i == j)
        return head;

	Node *curr = new Node(-1);
    curr->next = head;
    head = curr;
    
    Node *iprev = NULL, *jprev = NULL;
    while(curr != NULL and (i >= 0  or j >= 0)) {
        if(i == 0)
            iprev = curr;
        if(j == 0)
            jprev = curr;
        curr = curr->next;
        i--; j--;
    }
    
    Node *temp = iprev->next;
    iprev->next = jprev->next;
    jprev->next = temp;
    temp = iprev->next->next;
    iprev->next->next = jprev->next->next;
    jprev->next->next = temp;
    
    return head->next;
}

// Java Solution
public static LinkedListNode<Integer> swapNodes(LinkedListNode<Integer> head, int i, int j) {
		if(i == j)
            return head;
        LinkedListNode prevI = null, currI = head;
        while(i > 0 && currI != null) {
            prevI = currI;
            currI = currI.next;
            i--;
        }
        
        LinkedListNode prevJ = null, currJ = head;
        while(j > 0 && currJ != null) {
            prevJ = currJ;
            currJ = currJ.next;
            j--;
        }
        
        if(currI == null || currJ == null)
            return head;
        
        if(prevI != null)
            prevI.next = currJ;
        else
            head = currJ;
        
        if(prevJ != null)
            prevJ.next = currI;
        else
            head = currI;
        
        LinkedListNode temp = currI.next;
        currI.next = currJ.next;
        currJ.next = temp;
        
        return head;
	}