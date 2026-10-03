#include <iostream>
using namespace std;
//Struct of Linked List
struct Node {
  int data;
  struct Node *next;
  Node(int x){ //the constructor
     data=x;
     next=NULL;
  }
};
//fuction to print list
void printList(Node *head)
{
  Node *node = head;
  while(node!=NULL){
     cout << node->data << ' ';
     node = node->next;
  }
  cout << endl;
}
Node *insertAtBegining(Node *head, int newData);
Node *insertAtEnd(Node *head, int newData);

int main()
{
   int t;
   cin >> t;
   while(t--)
   {
     int n,ch,tmp;
     Node *head = NULL;
     cin >> n;
     for(int i=0;i<n;i++)
     {
       cin >> tmp >> ch;
       if(ch) head = insertAtEnd(head,tmp);
       else head=insertAtBegining(head,tmp);
     }
     printList(head);
   }
   return 0;
}
// function inserts the data in front of the list
Node *insertAtBegining(struct Node *head, int newData) {
   // Your code here
   struct Node *temp=new Node(newData);
   if(head==NULL) return temp;
   temp->next=head;
   return temp;
}

// function appends the data at the end of the list
Node *insertAtEnd(struct Node *head, int newData)  {
   // Your code here
   struct Node *temp = new Node(newData);
   struct Node *last= head;
   if(head==NULL) return temp;
   
   while(last->next!=NULL)
     last = last->next;
   last->next = temp;
   return head;
}
