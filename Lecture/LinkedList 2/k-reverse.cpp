/***
 * Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 
 * 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
 * Test Case:
        1 -> 2 -> 3 -> 4 -> 5
        k = 2; 2 -> 1 -> 4 -> 3 -> 5
        k = 3; 3 -> 2 -> 1 -> 5 -> 4
 ***/
Node *kReverse(Node *head, int k)
{
    if (k < 2 or head == NULL or head->next == NULL)
        return head;

    Node *newHead = new Node(-1);
    newHead->next = head;
    head = newHead;

    Node *curr = head->next, *prev = NULL, *prevHead = head, *subHead = NULL;

    while (curr != NULL)
    {
        subHead = curr;
        int t = 0;
        while (t < k and curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            t++;
        }
        prevHead->next = prev;
        prev = NULL;
        prevHead = subHead;
    }
    return head->next;
}

// Java
/*
Time Complexity : O(n)
Space Complexity : O(n / k)
Where 'n' is size of the Singly Linked List
*/
public class Solution {
public static LinkedListNode<Integer> kReverse(LinkedListNode<Integer> head, int k) {
        if (k == 0 || k == 1)
            return head;
        LinkedListNode<Integer> current = head;
        LinkedListNode<Integer> fwd = null;
        LinkedListNode<Integer> prev = null;
        int count = 0;
        /* Reverse first k nodes of linked list */
        while (count < k && current != null) {
            fwd = current.next;
            current.next = prev;
            prev = current;
            current = fwd;
            count++;
        }
        if (fwd != null)
            head.next = kReverse(fwd, k);
        
        return prev;
    }
}