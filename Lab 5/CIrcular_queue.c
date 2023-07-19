/* 1) Design your implementation of the circular queue. The circular queue is a linear data
      structure in which the operations are performed based on FIFO (First In First Out)
      principle, and the last position is connected back to the first position to make a circle. It is
      also called "Ring Buffer" .                       */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Abstract Data Type
typedef struct Queue
{
    // these are general properties of queue
    int M;
    int F;
    int R;
    int *array;
}Queue;
// underflow condition
bool isEmpty(Queue *Q)
{
    return Q -> F == -1 && Q -> R == -1;
}
// overflow condition
bool isFull(Queue *Q)
{
    return Q -> F == (Q -> R + 1) % Q -> M;
}
// enqueue function
void enqueue(Queue *Q, int data)
{
    // checking the overflow condition
    if (isFull(Q))
    {
        printf("Queue is Full");
        return;
    }
    // if we are insertin the first element in Circular queue
    else if (Q -> F == -1)
    {
        Q -> F = Q -> R = 0;
    }
    // this is general updation in a Circular queue implementation
    else
    {
        Q -> R = (Q -> R + 1) % Q -> M;
    }
    // setting data
    Q -> array[Q -> R] = data;
}
// dequeue function
int dequeue(Queue *Q)
{
    // underflow condition
    if (isEmpty(Q))
    {
        printf("Queue is empty");
        return INT_MIN;
    }
    else
    {
        // stroing value of front in temp
        int temp = Q -> array[Q -> F];
        // when we are deleting last element
        if (Q -> R == Q -> F)
        {
            Q -> R = Q -> F = -1;
        }
        // // this is general updation in a Circular queue implementation
        else
        {
            Q -> F = (Q -> F + 1) % Q -> M;
        }
        return temp;
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
    return Q -> array[Q -> F];
}
// size function
int QSize(Queue *Q)
{
    return Q -> R - Q -> F + 1;
}
void main() 
{
    // creating a queue inside a heap
    Queue *Q = (Queue *) malloc (sizeof(Queue));
    // size of Circular Queue
    Q -> M = 7;
    // let Front and Rear be -1
    Q -> F = Q -> R = -1;
    // creating array of the created Queue in heap
    Q -> array = (int *) malloc (Q -> M * sizeof(int));
    // operations
    enqueue(Q, 89);
    enqueue(Q, 75);
    enqueue(Q, 85);
    enqueue(Q, 56);
    printf("%d\n", QSize(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", front(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", QSize(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
}