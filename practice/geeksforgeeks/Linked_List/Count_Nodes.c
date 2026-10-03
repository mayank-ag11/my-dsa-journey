//Recursive Approach
int getCount(struct Node* head){

    if(head==NULL) return 0;
    else return 1+getCount(head->next);
}

//Iterative Approach
int getCount(struct Node* head){
    int ctr=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
	ctr++;
	temp=temp->next;
    }
    return ctr;
}
