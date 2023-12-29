#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

struct Node* search(struct Node* root, int key) 
{
    if (root == NULL || root->data == key) 
    {
        return root;
    }
    if (key > root->data) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() 
{
    struct Node* root = NULL;

    int n, key;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the key values:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        root = insert(root, key);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);

    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Key %d found in the BST.\n", key);
    } else {
        printf("Key %d not found in the BST.\n", key);
    }

    return 0;
}

