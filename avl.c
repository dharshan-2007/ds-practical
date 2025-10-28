#include <stdio.h>
#include <stdlib.h>

// AVL tree node structure
struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Get height of node
int height(struct Node* node)
{
    if (node == NULL) return 0;
    return node->height;
}

// Create new node
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Get balance factor of node
int getBalance(struct Node* node)
{
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Right rotate subtree rooted with y
struct Node* rightRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x)
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Insert node in AVL tree
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Main function demonstrating AVL tree operations
int main()
{
    struct Node* root = NULL;

    // Insert nodes to demonstrate balancing
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // Triggers RR rotation
    root = insert(root, 40);
    root = insert(root, 50); // Triggers RR rotation
    root = insert(root, 25); // No rotation needed
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
