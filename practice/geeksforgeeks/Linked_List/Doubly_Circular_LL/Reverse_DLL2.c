/* Function to reverse a Doubly Linked List */
void reverse(struct Node **head_ref) 
{ 
     struct Node *temp = NULL;   
     struct Node *current = *head_ref; 
       
     /* swap next and prev for all nodes of  
       doubly linked list */
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     /* Before changing head, check for the cases like empty  
        list and list with only one node */
     if(temp != NULL ) 
        *head_ref = temp->prev; 
}
Very Simple Code:-

void reverse(struct node **head_ref)
{

struct node *curr; //point to current Node
while((*head_ref)!=NULL){ //Run while loop till head_ref !=NULL i.e reach at the end
curr = *head_ref; //point to current Node
(*head_ref) = (*head_ref)->next; //move head to next Node
curr->next = curr->prev; //currentNode->next should point to current->prev
curr->prev = (*head_ref); // currentNode->prev should point to headNode to reverse it
}
(*head_ref) = curr;
}
