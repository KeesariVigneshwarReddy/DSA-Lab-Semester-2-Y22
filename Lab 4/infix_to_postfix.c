/* 1) Convert the infix expression to a postfix expression */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct stack 
{
    int capacity;
    int top;
    char *array;
}stack;
bool isEmpty(stack *s)
{
    if (s -> top == -1)
    {
        return true;
    }
    return false;
}
bool isFull(stack *s)
{
    if (s -> top == s -> capacity - 1)
    {
        return true;
    }
    return false;
}
void push(stack *s, char data)
{
    if (isFull(s))
    {
        return;
    }
    s -> array[++(s -> top)] = data;
}
char pop(stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    char temp = s -> array[s -> top];
    (s -> top)--;
    return temp;
}
char top(stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s -> array[s -> top];
}
bool is_operator(char c) 
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}
int get_precedence(char c) 
{
    if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infixToPostfix(stack *s, char infix[], char postfix[]) 
{
    int i, j;
    for(i = 0, j = 0; infix[i] != '\0'; i++) 
    {
        if(isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if(is_operator(infix[i])) 
        {
            while(top >= 0 && get_precedence(top(s)) >= get_precedence(infix[i])) 
            {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
        else if(infix[i] == '(')
        {
            push(s, infix[i]);
        }
        else if(infix[i] == ')') 
        {
            while(top(s) != '(') 
            {
                postfix[j++] = pop(s);
            }
            pop(s);
        }
    }
    while(s -> top >= 0) 
    {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}
void main() 
{
    stack *s1 = (stack *) malloc(sizeof(stack));
    s1 -> capacity = 100;
    s1 -> top = -1;
    s1 -> array = (char *) malloc (s1 -> capacity * sizeof(char));
    char infix[100], postfix[100];
    printf("Enter infix expression = ");
    scanf("%s", infix);
    infixToPostfix(s1, infix, postfix);
    printf("Postfix expression = %s\n", postfix);
}