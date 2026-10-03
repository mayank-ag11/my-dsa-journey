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

bool isPalindrome(Node *head)
{
    if(head == NULL or head->next == NULL)
        return true;
    
    Node *fast = head, *slow = head;
    while(fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reversing the second half
    Node *prev = NULL;
    Node *curr = slow;
    while(curr != NULL) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    curr = head;
    while(prev != NULL) {
        if(curr->data != prev->data)
            return false;
        prev = prev->next;
        curr = curr->next;
    }
    return true;
}