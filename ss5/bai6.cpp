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

// Ham in
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("<-->%d<-->", temp->data);
        temp = temp->next;
//        printf("NULL");
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

    // In
    printf("Danh sach: ");
    printList(head);

}
