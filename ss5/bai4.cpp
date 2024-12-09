#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;


// Ham dem so luong
int countElements(Node* head) {
    int count = 0;
    Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
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

Node* createNode(int data){
	// Cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
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

    // In danh sach
    printf("Danh sach: ");
    printList(head);

    // so luong phan tu
    int count = countElements(head);
    printf("so luong phan tu trong danh sach: %d\n", count);

    return 0;
}
