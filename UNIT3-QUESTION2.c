#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    char page[50];
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL, *tail = NULL,*current = NULL;
void visitPage(char* page) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->page, page);
    newNode->prev = tail;
    newNode->next = NULL;
    if (tail != NULL) {
        tail->next = newNode;
    }

    if (head == NULL) {
        head = newNode;
    }
    tail = newNode;
    current = newNode;
    printf("Visited: %s\n", page);
}
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Went back to: %s\n", current->page);
    } else {
        printf("No previous page to go back to.\n");
    }
}
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Went forward to: %s\n", current->page);
    } else {
        printf("No next page to go forward to.\n");
    }
}
void deletepage(char* page) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->page, page) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
            }
            if (current == temp) {
                current = temp->prev != NULL ? temp->prev : temp->next;
            }
            free(temp);
            printf("page  %s deleted from the history.\n", page);
            return;
        }
        temp = temp->next;
    }
    printf("Page %s not found.\n", page);
}
void displayForwardHistory() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("No pages in history.\n");
        return;
    }
    printf("Forward History: ");
    while (temp != NULL) {
        printf("%s -> ", temp->page);
        temp = temp->next;
    }
    printf("NULL\n");
}
void displayBackwardHistory() {
    struct Node* temp = tail;
    if (temp == NULL) {
        printf("No pages in history.\n");
        return;
    }
    printf("Backward History: ");
    while (temp != NULL) {
        printf("%s -> ", temp->page);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main() {
    int choice;
    char page[50];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Visit Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Delete Page from History\n");
        printf("5. Display Forward History\n");
        printf("6. Display Backward History\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                printf("Enter page name to visit: ");
                scanf("%s", page);
                visitPage(page);
                break;
            }   
            case 2:{
                goBack();
                break;
            }   
            case 3:{
                goForward();
                break;
            }
            case 4:{
                printf("Enter page name to delete from history: ");
                scanf("%s", page);
                deletepage(page);
                break;
            }
            case 5:{
                displayForwardHistory();
                break;
            }           
            case 6:{        
                displayBackwardHistory();
                break;
            }
            case 7:{
                exit(0);
            }
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}