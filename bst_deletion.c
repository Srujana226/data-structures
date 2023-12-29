#include <stdio.h>
#include <stdlib.h>

struct Node {
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

struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
       
        if (root->left == NULL) 
	{
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
	else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    int n, key;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the key values:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Enter the key to delete: ");
    scanf("%d", &key);

    printf("Inorder Traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, key);

    printf("Inorder Traversal after deletion of %d: ", key);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
