/***
 * You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
 ***/
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
// Time - O(n)
Node *appendLastNToFirst(Node *head, int n)
{
    if(n == 0 or head == NULL)
        return head;
    
    Node *fast = head, *slow = head, *initialHead = head;
    
    for(int i = 0; i < n; i++)
        fast = fast->next;
    
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    head = slow->next;
    slow->next = NULL;
    fast->next = initialHead;
    return head;
}

/* Brute Force
Node *appendLastToFirst(Node *head) {
    Node *curr = head;
    if(head == NULL or head->next == NULL)
        return head;
    
    while(curr->next->next != NULL)
        curr = curr->next;
    
    Node *temp = curr->next;
    curr->next = NULL;
    temp->next = head;
    return temp;
}

Node *appendLastNToFirst(Node *head, int n)
{
    while(n--) {
        head = appendLastToFirst(head);
    }
    return head;
}*/