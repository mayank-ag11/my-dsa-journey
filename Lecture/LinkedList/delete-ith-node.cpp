/****************************************************************
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };
*****************************************************************/
// Indexing of the linked list starts from 0
// Recursively
Node *deleteNodeRec(Node *head, int pos) {
	if(head == NULL)
        return head;
    if(pos == 0) {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    
    Node *temp = deleteNodeRec(head->next, pos-1);
    head->next = temp;
    return head;
}
// Iteratively
Node *deleteNode(Node *head, int pos) {
    if(head == NULL)
        return head;
    if(pos == 0)
        return head->next;
    
    Node *curr = head;
    while(curr != NULL and pos > 1) {
        curr = curr->next;
        pos--;
    }
    
    if(curr != NULL and curr->next != NULL) {
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    return head;
}

/***
// In Java
public class Solution {
	public static LinkedListNode<Integer> deleteNode(LinkedListNode<Integer> head, int pos) {
        if(head == null)
            return null;
		if(pos == 0) 
            return head.next;
        
        LinkedListNode<Integer> curr = head;
        while(curr != null && pos > 1) {
            curr = curr.next;
            pos--;
        }
        if(curr != null && curr.next != null)
        	curr.next = curr.next.next;
        return head;
	}
}
***/