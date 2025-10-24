#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void insertfront(struct node** head, int num)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = *head;
    *head = newnode;
}

void insertback(struct node** head, int num)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void deletefront(struct node** head)
{
    struct node* temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
        return;
    }
    *head = (*head)->next;
    free(temp);
}

void deleteback(struct node** head)
{
    struct node* temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void display(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    struct node* head = NULL;
    int ch, ele;
    printf("\nSingly linked list operations\n");
    while (1)
    {
        printf("1. Insert front\n");
        printf("2. Insert back\n");
        printf("3.Display\n");
        printf("4. Delete front\n");
        printf("5. Delete back\n");
        printf("6. Exit\n");
        printf("\nEnter Your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d", &ele);
            insertfront(&head, ele);
            break;
        case 2:
            printf("Enter the element:");
            scanf("%d", &ele);
            insertback(&head, ele);
            break;
        case 3:
            display(head);
            break;
        case 4:
            deletefront(&head);
            break;
        case 5:
            deleteback(&head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
            exit(1);
        }
    }
}
