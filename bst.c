#include <stdio.h>
#include <stdlib.h>


struct node
{
    int key;
    struct node *left, *right;
};


struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}


struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}


struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main()
{
    struct node* root = NULL;


    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int searchKey = 40;
    if (search(root, searchKey) != NULL)
    {
        printf("%d found in BST\n", searchKey);
    }
    else
    {
        printf("%d not found in BST\n", searchKey);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("After deleting 20 (leaf): ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("After deleting 30 (one child): ");
    inorder(root);
    printf("\n");
    root = deleteNode(root, 50);
    inorder(root);
    printf("\n");

    return 0;
}
