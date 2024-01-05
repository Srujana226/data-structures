#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node* left;
    int data;
    struct node* right;
};

struct node* createnode(int key) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        return createnode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

void inordertraversal(struct node* root) {
    if (root != NULL) {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}

void preordertraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void postordertraversal(struct node* root) {
    if (root != NULL) {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int n, key;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the key values:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        root = insert(root, key);
    }
    printf("Inorder Traversal: ");
    inordertraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preordertraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postordertraversal(root);
    printf("\n");

    return 0;
}
