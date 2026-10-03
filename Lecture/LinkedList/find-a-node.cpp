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
// Recursively
int findNode(Node *head, int n){
    if(head == NULL)
        return -1;
    if(head->data == n)
        return 0;
    
    int ans = findNode(head->next, n);
    if(ans != -1)
        return ans + 1;
}

// Iteratively (Java)
/****************************************************************
	Following is the class structure of the Node class:

	class LinkedListNode<T> {
    	T data;
    	LinkedListNode<T> next;
    
    	public LinkedListNode(T data) {
        	this.data = data;
    	}
	}
*****************************************************************/
public class Solution {
	public static int findNode(LinkedListNode<Integer> head, int n) {
		int ctr = 0;
        while(head != null) {
            if(head.data == n)
                return ctr;
            ctr++;
            head = head.next;
        }
        return -1;
	}
}