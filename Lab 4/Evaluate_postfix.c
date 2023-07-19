/* 2) Evaluate a postfix expression */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct stack 
{
    int capacity;
    int top;
    int *array;
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
void push(stack *s, int data)
{
    if (isFull(s))
    {
        return;
    }
    s -> array[++(s -> top)] = data;
}
int pop(stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    int temp = s -> array[s -> top];
    (s -> top)--;
    return temp;
}
int top(stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s -> array[s -> top];
}
int evaluatePostfix(stack *s, char postfix[])
{
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            push(s, (int)ch - 48);
        }
        else 
        {
            int A = pop(s);
            int B = pop(s);
            switch(ch)
            {
                case '+' : push(s, B + A);
                break;
                case '-' : push(s, B - A);
                break;
                case '*' : push(s, B * A);
                break;
                case '/' : push(s, B / A);
                break;
            }
        }
    }
    return pop(s);
}
void main() 
{
    stack *s = (stack *) malloc(sizeof(stack));
    s -> capacity = 100;
    s -> top = -1;
    s -> array = (int *) malloc (s -> capacity * sizeof(int));
    char postfix[100];
    printf("Enter postfix expression = ");
    scanf("%s", postfix);
    printf("Result = %d\n", evaluatePostfix(s, postfix));
}