/*  3) Balanced parentheses expressions mean that each opening symbol has a
       corresponding closing symbol and the pairs of parentheses are properly nested in the
       expression. For example, the expression [12+(23+14)-9] is a balanced parenthesis
       expression and [3 + { 2* (9 - 2)/ 5] is not a balanced expression.

       Write a program to examine whether the pairs of parenthesis “(“, “)”, “[“, “]”, “{“,
       “}” in an expression are correct in order.                                                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
        printf("Stack is full");
        return;
    }
    s -> array[++(s -> top)] = data;
}
char pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty stack");
        return (char)-1;
    }
    char temp = s -> array[s -> top];
    (s -> top)--;
    return temp;
}
char top(stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty stack");
        return (char)-1;
    }
    return s -> array[s -> top];
}
bool checkBalanced(stack *s, char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
             push(s, str[i]);
        }
        else
        {
            if (str[i] == ')')
            {
                if(top(s) == '(')
                {
                    pop(s);
                }
                else
                {
                    return false;
                }
            }
            else if (str[i] == ']')
            {
                if(top(s) == '[')
                {
                    pop(s);
                }
                else
                {
                    return false;
                }
            }
            else if (str[i] == '}')
            {
                if(top(s) == '{')
                {
                    pop(s);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (isEmpty(s))
    {
        return true;
    }
    return false;
}
void main()
{
    stack *s = (stack *) malloc(sizeof(stack));
    s -> capacity = 100;
    s -> top = -1;
    s -> array = (char *) malloc (s -> capacity * sizeof(char));
    char str[100];
    printf("Enter String = ");
    scanf("%s", str);
    if (checkBalanced(s, str))
    {
         printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }
}