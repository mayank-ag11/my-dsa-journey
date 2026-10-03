Node *bubbleSort(Node *head)
{
    if(head == NULL or head->next == NULL)
        return head;
    
    Node *newHead = new Node(-1);
    newHead->next = head;
    bool swapped;
    
    while(true) {
        Node *curr = newHead->next, *prev = newHead;
        swapped = false;
        
        while(curr->next != NULL) {
            if(curr->next->data < curr->data) {
                swapped = true;
                Node *temp = curr->next;
                curr->next = temp->next;
                prev->next = temp;
                temp->next = curr;
                prev = temp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        if(swapped == false)
            break;
    }
    
    return newHead->next;
}

// Java
/*
Time Complexity : O(n^2)
Space Complexity : O(1)
Where 'n' is size of the Singly Linked List
*/
public class Solution {
    private static int length(LinkedListNode<Integer> head) {
        int count = 0;
        while (head != null)
        {
            head = head.next;
            count++;
        }
        return count;
    }
    public static LinkedListNode<Integer> bubbleSort(LinkedListNode<Integer> head) {
        int n = length(head);
        for (int i = 0; i < (n - 1); i++) {
            LinkedListNode<Integer> prev = null;
            LinkedListNode<Integer> curr = head;
            for (int j = 0; j < (n - i - 1); j++) {
                if (curr.data <= curr.next.data) {
                    prev = curr;
                    curr = curr.next;
                }
                else {
                    if (prev == null) {
                        LinkedListNode<Integer> fwd = curr.next;
                        head = head.next;
                        curr.next = fwd.next;
                        fwd.next = curr;
                        prev = fwd;
                    }
                    else {
                        LinkedListNode<Integer> fwd = curr.next;
                        prev.next = fwd;
                        curr.next = fwd.next;
                        fwd.next = curr;
                        prev = fwd;
                    }
                }
            }
        }
        return head;
    }
}