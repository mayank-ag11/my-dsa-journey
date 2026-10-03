#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node** head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void insertAtEnd(struct Node** head, int val) {
    // Create new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;

    if(*head == NULL) {
	*head = new_node;
	return;
    }

    // Find last node
    struct Node* last = *head;
    while(last->next != NULL)
	last = last->next;

    // Insert at End
    last->next = new_node;
}

void deleteFirstNode(struct Node** head) {
    if(*head == NULL) {
	printf("\tCannot delete as NO nodes in the linked-list\n");
	return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLastNode(struct Node** head) {
    if(*head == NULL) {
	printf("\tCannot delete as NO nodes in the linked-list\n");
	return;
    }
    // If list has only 1 element
    if((*head)->next == NULL) {
	free(*head);
	*head = NULL;
	return;
    }

    // Find the second last node
    struct Node *curr = *head;
    while(curr->next->next != NULL)
	curr = curr->next;

    free(curr->next);     // Free last node
    curr->next = NULL;    //  Change next of second last
}

void deleteSpecificNode(struct Node** head, int key) {
    // Store head node
    struct Node* temp = *head, *prev = NULL;

    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key) {
	*head = temp->next;   // Change head
	free(temp);           // Free old head
	return;
    }

    // Search for the key to be deleted
    // Keep track of prev node as we need to change "prev->next"
    while(temp != NULL && temp->data != key) {
	prev = temp;
	temp = temp->next;
    }

    // If key not found
    if(temp == NULL) {
	printf("\tCannot delete as no such node in the linked-list\n");
	return;
    }

    // Unlink the node from list
    prev->next = temp->next;
    free(temp);
}

void findNode(struct Node* head, int key) {
    int pos = 1;
    struct Node* curr = head;

    while(curr != NULL && curr->data != key) {
	pos++;
	curr = curr->next;
    }

    if(curr != NULL) {
	printf("\tValue %d node is at position %d in the linked list.\n\tDifference in its allocated memory to that of current head : %ld\n", key, pos, curr - head);
    }
    else
	printf("\tCannot find any such node in the linked-list\n");
}

void size(struct Node* head) {
    int ctr = 0;
    struct Node* curr = head;
    while(curr != NULL) {
	ctr++;
	curr = curr->next;
    }
    printf("\tSize of the linked list = %d\n", ctr);
}

void displayList(struct Node* head) {
    if(head == NULL) {
	printf("\tEmpty\n");
	return;
    }

    printf("\tLinked list: ");
    while(head->next != NULL) {
	printf("%d => ", head->data);
	head = head->next;
    }
    printf("%d\n", head->data);
}

void deleteList(struct Node** head) {
    struct Node* curr = *head;
    struct Node* next;

    while(curr != NULL) {
	next = curr->next;
	free(curr);
	curr = next;
    }
    *head = NULL;
}

int main() {
    int input = 0, val;
    struct Node *head = NULL;

    printf("Enter the choice:\n");
    while(1) {
	scanf("%d", &input);
	switch(input) {
	    case 0:
		deleteList(&head);
		exit(0);
	    case 1:
		printf("Enter the data value:\n");
		scanf("%d", &val);
		insertAtBeginning(&head, val);
		printf("Enter the choice:\n");
	        break;
	    case 2:
		printf("Enter the data value:\n");
		scanf("%d", &val);
		insertAtEnd(&head, val);
		printf("Enter the choice:\n");
	        break;
            case 3:
		deleteFirstNode(&head);
		printf("Enter the choice:\n");
                break;
            case 4:
		deleteLastNode(&head);
		printf("Enter the choice:\n");
                break;
            case 5:
		printf("Enter the data value:\n");
		scanf("%d", &val);
		deleteSpecificNode(&head, val);
		printf("Enter the choice:\n");
                break;
            case 6:
		printf("Enter the data value:\n");
		scanf("%d", &val);
		findNode(head, val);
		printf("Enter the choice:\n");
                break;
            case 7:
		size(head);
		printf("Enter the choice:\n");
                break;
            case 8:
		displayList(head);
		printf("Enter the choice:\n");
                break;
            default:
		printf("\tWrong Input.\nEnter your choice again:\n");
	}
    }
}
