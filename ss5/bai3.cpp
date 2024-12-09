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



// Ham xoa phan tu
void deleteLastNode(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    Node* temp = *head;

    // Neu chi co 1 nut
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // Duyet den nut cuoi
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Xoa nut cuoi
    temp->prev->next = NULL;
    free(temp);
}

// Ham in
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("<-->%d<-->NULL ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
	Node* head = NULL;

    // Them phan tu
    Node* first = createNode(10);
    head = first;
    Node* second = createNode(20);
    first->next = second;
    second->prev = first;
    Node* third = createNode(30);
    second->next = third;
    third->prev = second;

    // In danh sach
    printf("Danh sach truoc khi xoa: ");
    printList(head);

    // Xoa phan tu cuoi
    deleteLastNode(&head);

    // In danh sach sau khi xoa
    printf("Danh sach sau khi xoa: ");
    printList(head);

    return 0;
}
