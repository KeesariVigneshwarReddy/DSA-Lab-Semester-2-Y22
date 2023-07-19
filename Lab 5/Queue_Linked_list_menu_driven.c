/* 3) Design a menu driven program (Queue using linked list) */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// this is structure node 
typedef struct node 
{
    int data;
    struct node *next;
}node;
// Abstract Data Type
typedef struct Queue
{
    // general properties
    int count;
    // since F and R are pointers to node
    node* F;
    node* R;
}Queue;
// underflow condition
bool isEmpty(Queue *Q)
{
    return Q -> F == NULL;
}
// overflow contion do not exist in Linked list implementation
// enqueue function
void enqueue(Queue *Q, int data)
{
    // creating a node
    node *newNode = (node *) malloc (sizeof(node));
    // assigning data to it
    newNode -> data = data;
    // let newNode -> next point to NULL
    newNode -> next = NULL;
    // inserting first node
    if(isEmpty(Q))
    {
        Q -> F = Q -> R = newNode;
    }
    else
    {
        Q -> R -> next = newNode;
        Q -> R = newNode;
    }
}
// dequeue function
int dequeue(Queue *Q)
{
    // checking underflow condition
    if (isEmpty(Q))
    {
        printf("Underflow");
    }
    else
    {
        // storing front data
        int tempData = Q -> F -> data;
        // let temp point to null
        node *temp = Q -> F;
        // updating front
        Q -> F = Q -> F -> next;
        // clearing temp from memory
        free(temp);
        return tempData;
    }
}
// front function
int front(Queue *Q)
{
    // underflow condition
    if (isEmpty(Q))
    {
        return INT_MIN;
    }
    return Q -> F -> data;
}
// size function
int QSize(Queue *Q)
{
    int count = 0;
    node *temp = Q -> F;
    while (temp != NULL)
    {
        temp = temp -> next;
        count++;
    }
    return count;
}
void main() 
{
    // creating a Queue in heap
    Queue *Q = (Queue *) malloc (sizeof(Queue));
    // let F and R point to NULL
    Q -> F = Q -> R = NULL;
    int choice;
    do
    {
         printf("Enter 1 -> for Enqueuing\n");
         printf("Enter 2 -> for Dequeuing\n");
         printf("Enter 3 -> for Printing Size\n");
         printf("Enter 4 -> for Printing Front\n");
         printf("Enter 0 -> for Exiting program\n");
         printf("Enter choice = ");
         scanf("%d", &choice);
         printf("\n");
         switch(choice)
         {
             case 1 :  {
                           int data;
                           printf("Enter data you want to enqueue = ");
                           scanf("%d", &data);
                           printf("\n");
                           enqueue(Q, data);
                       }
             break;
             case 2 :  {
                           printf("%d is Dequeued\n", dequeue(Q));
                           printf("\n");
                       }
             break;
             case 3 :  {
                           printf("Size = %d\n", QSize(Q));
                           printf("\n");
                       }
             break;
             case 4 :  {
                           printf("Front = %d\n", front(Q));
                           printf("\n");
                       }
             break;
             case 0 :  {
                           printf("Exiting Program\n");
                           printf("\n");
                           return;
                       }
             break;
         }
    } while(choice != 0);
    // operation
    /*enqueue(Q, 89);
    enqueue(Q, 75);
    enqueue(Q, 85);
    enqueue(Q, 56);
    printf("%d\n", QSize(Q));     ans = 4
    printf("%d\n", dequeue(Q));   ans = 89
    printf("%d\n", front(Q));     ans = 75
    printf("%d\n", dequeue(Q));   ans = 75
    printf("%d\n", QSize(Q));     ans = 2
    printf("%d\n", dequeue(Q));   ans = 85
    printf("%d\n", dequeue(Q));   ans = 56
    printf("%d\n", dequeue(Q));   ans = queue is empty garbage     */
}