#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

struct Node *findMin(struct Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int value) {
    if (root == NULL) {
        printf("Value %d not found in the tree.\n", value);
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {

            free(root);
            return NULL;
        } else if (root->left == NULL) {

            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {

            struct Node *temp = root->left;
            free(root);
            return temp;
        } else {

            struct Node *successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    int i;

    for (i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Inorder before any deletion: ");
    inorder(root);
    printf("\n\n");

    printf("Case 1 - Delete a leaf node (0 children): deleting 20\n");
    root = deleteNode(root, 20);
    printf("Inorder after deletion:      ");
    inorder(root);
    printf("\n\n");

    printf("Case 2 - Delete a node with 1 child: deleting 60, then 70\n");
    printf("(removing 60 first leaves 70 with a single child, 80)\n");
    root = deleteNode(root, 60);
    root = deleteNode(root, 70);
    printf("Inorder after deletion:      ");
    inorder(root);
    printf("\n\n");

    printf("Case 3 - Delete a node with 2 children: deleting root 50\n");
    root = deleteNode(root, 50);
    printf("Inorder after deletion:      ");
    inorder(root);
    printf("\n");

    return 0;
}