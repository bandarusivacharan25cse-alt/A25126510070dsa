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

void inorder(struct Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int search(struct Node *root, int value) {
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

int main() {
    struct Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    int i, key;

    for (i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Inorder traversal:   ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal:  ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    key = 60;
    printf("\nSearching for %d: %s\n", key, search(root, key) ? "Found" : "Not found");

    key = 25;
    printf("Searching for %d: %s\n", key, search(root, key) ? "Found" : "Not found");

    printf("\nInorder traversal visits left subtree, then root, then right subtree.\n");
    printf("Since every left child is smaller and every right child is larger than\n");
    printf("its parent in a BST, this ordering naturally produces sorted values.\n");

    return 0;
}