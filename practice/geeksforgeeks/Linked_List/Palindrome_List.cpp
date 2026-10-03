/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Reverse Linked List
void reverse(struct Node **head_ref)
{
    struct Node *prev=NULL;
    struct Node *temp,*current=*head_ref;
    while(current!=NULL)
    {
      temp=current;
      current=current->next;
      temp->next=prev;
      prev=temp;
    }
    *head_ref=prev;
}
//Compare two Lists
bool compareLists(struct Node *head1,struct Node *head2)
{
    struct Node *temp1=head1;
    struct Node *temp2=head2;
    
    while(temp1&&temp2)
    {
        if(temp1->data==temp2->data)
          {
            temp1=temp1->next;
            temp2=temp2->next;
          }
        else
          return 0;
    }
    //Both are empty
    if(temp1==NULL&&temp2==NULL)
      return 1;
      
    //will reach here if one is NULL and other is not
    return 0;
}
bool isPalindrome(Node *head)
{
   bool res=true;
   if(head!=NULL && head->next!=NULL)
    {
      struct Node *slow,*fast,*mid;
      struct Node *second_half, *prev_of_slow=head;
      slow=fast=head;
      mid=NULL;
      //Get Middle of List
      while(fast && fast->next)
      {
        prev_of_slow=slow;
        slow=slow->next;
        fast=fast->next->next;
      }
      /*fast_ptr would become NULL when there are even elements in list.  
        And not NULL for odd elements. We need to skip the middle node  
        for odd case and store it somewhere so that we can restore the 
        original list*/
      if(fast!=NULL)
      {
        mid=slow;
        slow=slow->next;
      }
      //Reverse second half and then compare with first half
      second_half=slow;
      prev_of_slow->next=NULL; //NULL terminate first half
      reverse(&second_half); //Reverse second half
      res= compareLists(head,second_half);
      
      //Construct Original List Back
      reverse(&second_half); //Reverse second half again
      
      if(mid!=NULL)
      {
          prev_of_slow->next=mid;
          mid->next=second_half;
      }
      else
        prev_of_slow->next=second_half;
    }
    return res;
}
