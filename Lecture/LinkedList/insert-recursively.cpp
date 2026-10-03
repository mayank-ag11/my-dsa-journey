Node* insertNode(Node *head, int i, int data) {
	if(head == NULL)
        return head;
    if(i == 0) {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    
    Node *temp = insertNode(head->next, i-1, data);
    head->next = temp;
    return head;
}