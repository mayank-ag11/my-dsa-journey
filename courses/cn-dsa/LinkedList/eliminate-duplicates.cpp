/***
 * You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
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
Node *removeDuplicates(Node *head)
{
    if(head == NULL)
        return head;
    
    Node *prev = head, *curr = head->next;
    
    while(prev != NULL and curr != NULL) {
        if(prev->data != curr->data) {
            prev = prev->next;
            curr = curr->next;
        }
        else {
            Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
    }
    
    return head;
}

// Java
/*
public class Solution {
public static LinkedListNode<Integer> removeDuplicates(LinkedListNode<Integer> head) {
        if (head == null) {
            return head;
        }
        LinkedListNode<Integer> currHead = head;
        while (currHead.next != null) {
            if (currHead.data.equals(currHead.next.data))
                currHead.next = currHead.next.next;
            else
                currHead = currHead.next;
        }
        return head;
    }
}*/