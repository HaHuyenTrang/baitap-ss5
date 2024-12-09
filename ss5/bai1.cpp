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


// Ham them nut vao ds 
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Ham in danh sach cuoi den dau
void printListReverse(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    // Di chuyen den nut cuoi cung
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // danh sach tu cuoi ve dau
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
	 Node* head = NULL;

    // cac phan tu
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    // In 
    printf("Danh sach tu cuoi ve dau: ");
    printListReverse(head);

    return 0;
}
