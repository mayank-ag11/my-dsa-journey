package Lecture.LinkedList;

class Node {
  int data;
  Node next;
  Node(){}
  Node(int d) {
    data=d;
  }
}
class Result {
    static int checkPalindrome(Node head) {
          Node slow_ptr = head;
          Node fast_ptr = head;
  
           
              while (fast_ptr != null && fast_ptr.next != null)
              {
                  fast_ptr = fast_ptr.next.next;
                  slow_ptr = slow_ptr.next;
              }
      Node prev = null;
      Node next = null;
      Node current = slow_ptr;
      while (current != null) {
              next = current.next;
              current.next = prev;
              prev = current;
              current = next;
      }
      fast_ptr = head;
      while(prev!=null)
      {
        if(prev.data != fast_ptr.data)
          return 0;
        prev = prev.next;
        fast_ptr = fast_ptr.next;
      }
      return 1;
    }
  }