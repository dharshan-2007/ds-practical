//
// Created by Dharshan on 23-10-2025.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *top=NULL;
struct node *postfix=NULL;

void push(char ch)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ch;
    newnode->next=top;
    top=newnode;
}

char pop()
{
    char data;
    struct node *temp=top;
    if (top==NULL)
    {
        return 0;
    }
    data=temp->data;
    top=top->next;
    free(temp);
    return data;
}

int chk_symbol(char ch)
{
    return (ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

struct node* insert(struct node *head,char ch)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ch;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}

void infix_to_postfix(char *str)
{
    char ch;
    for (int i=0;i<strlen(str);i++)
    {
        ch=str[i];
        if (isalnum(ch))
        {
            postfix=insert(postfix,ch);
        }
        else
        {
            if (ch=='(')
            {
                push(ch);
            }
            else if (ch==')')
            {
                while (top!=NULL && top->data!='(')
                {
                    postfix=insert(postfix,pop());
                }
                pop();
            }
            else
            {
               while (top!=NULL && precedence(ch)<=precedence(top->data))
               {
                   postfix=insert(postfix,pop());
               }
                push(ch);
            }

        }
    }
    while (top!=NULL)
    {
        postfix=insert(postfix,pop());
    }
}

void display()
{
    struct node *temp=postfix;
    while (temp!=NULL)
    {
        printf("%c",temp->data);
        temp=temp->next;
    }
}



int main()
{
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s",exp);
    infix_to_postfix(exp);
    display();
    return 0;
}
