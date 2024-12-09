#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* createNode(int data){
	// Cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}



// Ham chen nut vi tri chi dinh
void insertNodeAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    
    if (position < 0) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    
    // Chen vao vi 
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;

    // Tim nut truoc vi tri chen
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("Vi tri > do dai danh sach");
        free(newNode);
        return;
    }

    // Chen vi tri sau
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Ham in
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
	Node* head = NULL;

    // Them phan tu
    insertNodeAtPosition(&head, 10, 0);
    insertNodeAtPosition(&head, 20, 1);
    insertNodeAtPosition(&head, 30, 2);
    insertNodeAtPosition(&head, 40, 4); // Chen vao vi tri 1

    // In
    printf("Danh sach sau khi chen: ");
    printList(head);

    return 0;
}
