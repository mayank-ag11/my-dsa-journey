/***
 * Given a Singly Linked List of integers, delete all the alternate nodes in the list.
 * List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> null
   Alternate nodes will be:  20, 40, and 60.

   Hence after deleting, the list will be:
   Output: 10 -> 30 -> 50 -> null
 ***/
/*********************************************************
    // Following is the node structure
    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    
        ~Node() {
            if(next) {
                delete next;
            }
        }
    };
*********************************************************/
void deleteAlternateNodes(Node *head) {
    Node *curr = head;
    while(curr != NULL and curr->next != NULL) {
        Node *temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        delete temp;
        curr = curr->next;
    }
}