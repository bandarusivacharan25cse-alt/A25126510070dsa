#include <stdio.h>
#include <stdlib.h>
struct Node {
    int roll;
    struct Node* next;
};
struct Node* head = NULL;

void insertAtbeginning(int roll) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
}
void insertAtend(int roll) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
struct Node* search(int roll) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void deleteNode(int roll) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("Roll number %d deleted\n", roll);
        return;
    }
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Roll number %d not found\n", roll);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Roll number %d deleted\n", roll);
}
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Roll numbers in the list: ");
    while (temp != NULL) {
        printf("%d-> ", temp->roll);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, roll;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                printf("Enter roll number to insert at beginning: ");
                scanf("%d", &roll);
                insertAtbeginning(roll);
                break;
            }
            case 2:{
                printf("Enter roll number to insert at end: ");
                scanf("%d", &roll);
                insertAtend(roll);
                break;
            }
            case 3:{
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                struct Node* result = search(roll);
                if (result != NULL) {
                    printf("Roll number %d found in the list\n", roll);
                } else {
                    printf("Roll number %d not found in the list\n", roll);
                }
                break;
            }
            case 4:{
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteNode(roll);
                break;
            }
            case 5:{
                display();
                break;
            }
            case 6:{
                exit(0);
            }
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}