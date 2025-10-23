//
// Created by Dharshan on 23-10-2025.
//
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push()
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

void pop()
{
    int popped_item;
    struct node* temp = top;
    if (temp == NULL)
    {
        printf("Stack empty::Underflow\n");
        return;
    }
    top = top->next;
    popped_item = temp->data;
    free(temp);
    printf("Popped item is: %d\n", popped_item);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is : %d\n", top->data);
}

void display()
{
    struct node* temp = top;
    if (temp == NULL)
    {
        printf("Stack is empty\n");
    }
    while (temp != NULL)
    {
        printf("\n  %d \n", temp->data);
        temp = temp->next;
    }
}

void change()
{
    struct node* temp = top;
    int pos, val, count = 1;
    printf("Enter the position to change: ");
    scanf("%d", &pos);
    printf("Enter the new value :");
    scanf("%d", &val);
    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    temp->data = val;
    printf("Value Updated\n");
}

void main()
{
    int ch;
    printf("\nSTACK OPERATIONS\n");
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Change\n");
        printf("5.Display\n");
        printf("6. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            change();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice");
            break;
        }
    }
}

