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

// Ham dao nguoc dach sach lien ket doi
void reverseList(Node** head) {
    if (*head == NULL) {
        return; // ranh scah rong
    }

    Node* current = *head;
    Node* temp = NULL;

    // dao nguoc lien ket cac nut
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Ðat lai dau danh sach
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Ham in
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("<-->%d<-->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
	Node* head = NULL;

    // Them cac phan tu
    Node* first = createNode(10);
    head = first;
    Node* second = createNode(20);
    first->next = second;
    second->prev = first;
    Node* third = createNode(30);
    second->next = third;
    third->prev = second;

    // In danh sach ban dau
    printf("Danh sach ban dau: ");
    printList(head);

    // Ðao nguoc
    reverseList(&head);

    // In 
    printf("Danh sach dao nguoc: ");
    printList(head);

    return 0;
}
