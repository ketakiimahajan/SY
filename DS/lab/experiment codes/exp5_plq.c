#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to find the smallest node in the BST
struct Node* findSmallest(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Function to find the largest node in the BST
struct Node* findLargest(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050");
    struct Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 12);
    root = insert(root, 24);
    root = insert(root, 35);
    root = insert(root, 87);

    // Find the smallest and largest nodes
    struct Node* smallest = findSmallest(root);
    struct Node* largest = findLargest(root);

    if (smallest != NULL)
        printf("\nSmallest Node: %d\n", smallest->data);
    else
        printf("The tree is empty.\n");

    if (largest != NULL)
        printf("Largest Node: %d\n", largest->data);
    else
        printf("The tree is empty.\n");

    return 0;
}
