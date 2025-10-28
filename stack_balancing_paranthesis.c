

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stk[MAX];
int top=-1;

void push(char ele)
{
    if (top==MAX)
    {
        printf("Overflow stack\n");
        return;
    }
    stk[++top]=ele;
}

char pop()
{
    if (top==-1)
    {
        printf("Stack empty\n");
        return '\0';
    }
    return stk[top--];
}

int matching_pair(char char1,char char2)
{
    return (char1=='[' && char2==']')||(char1=='(' && char2==')') || (char1=='{' && char2=='}');
}

int balance(char *exp)
{
    for (int i=0;i<strlen(exp);i++)
    {
        if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(exp[i]);
        }
        else if (exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if (top==-1)
            {
                return 0;
            }
            if (!matching_pair(pop(),exp[i]))
            {
                return 0;
            }
        }
    }
    return top==-1;
}

void main()
{
    char ipexp[MAX];
    printf("\nEnter the expression: ");
    gets(ipexp);
    if (balance(ipexp))
    {
        printf("Expression is balanced");
    }
    else
    {
        printf("Expression is not balanced");
    }
}
