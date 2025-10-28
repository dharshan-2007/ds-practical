//
// Created by Dharshan on 24-10-2025.
//

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertfront(struct node** head, int value)
{
    struct node* newnode = createnode(value);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    newnode->next = *head;
    *head = newnode;
}

void insertback(struct node** head, int value)
{
    struct node* newnode = createnode(value);
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
    newnode->prev = temp;
}

void insertmiddle(struct node** head, int value, int pos)
{
    struct node* newnode = createnode(value);
    int count = 0;
    struct node* temp = *head;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (count == pos - 1 && temp != NULL)
    {
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    else
    {
        printf("Invalid position");
    }
}

void displayforward(struct node* head)
{
    struct node* temp = head;
    printf("NULL <-> ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displaybackward(struct node* head)
{
    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("NULL <->");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
}

void deletefront(struct node** head)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node* temp = *head;
    (*head) = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteback(struct node** head)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void main()
{
    int ch, val;
    struct node* head = NULL;
    printf("\nDoubly Linked List\n");
    while (1)
    {
        printf("1. Insert front\n");
        printf("2. Insert back\n");
        printf("3. Insert middlen\n");
        printf("4. Display forward\n");
        printf("5. Display backward\n");
        printf("6. Delete front\n");
        printf("7. Delete back\n");
        printf("8. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value:");
            scanf("%d", &val);
            insertfront(&head, val);
            break;
        case 2:
            printf("Enter the value:");
            scanf("%d", &val);
            insertback(&head, val);
            break;
        case 3:
            int pos;
            printf("Enter the value and position");
            scanf("%d%d", &val, &pos);
            insertmiddle(&head, val, pos);
            break;
        case 4:
            displayforward(head);
            break;
        case 5:
            displaybackward(head);
            break;
        case 6:
            deletefront(&head);
            break;
        case 7:
            deleteback(&head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice");
            return;
        }
    }
}
