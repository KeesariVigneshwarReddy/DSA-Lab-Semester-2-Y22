/* Q1) Write a C program to create a linked list. Split the created list into two lists: one
containing the elements of even indices, other containing elements of odd indiced the original list */
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void printList(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
}
// this function returns head pointer (of type node) 
// it also creates n nodes
node *createNode(int n)
{
    // creating a head pointer (of type node)
    node *head = NULL;
    // this is a extra pointer which will be required after creation of first node
    node *newNode = NULL;
    for (int i = 0; i < n; i++)
    {
        // this is first node we are creating
        if (i == 0)
        {
            // allocating memory for first node in heap
            head = (node *) malloc (sizeof(node));
            // let newNode point to head
            newNode = head;
        }
        // this statement gets executed when first node is already created
        else
        {
            // allocating memory for next node in heap
            newNode -> next = (node *) malloc (sizeof(node));
            // let newNode point to next node
            newNode = newNode -> next;
        }
        // inputing data at every node
        scanf("%d", &newNode -> data);
    }
    // finally returning head so that we can traverse through it from main function
    return head;
}
// this function splits the main LL to odd LL and even LL
// since we are passing address of pointers 
// we should use double pointer as parameter
void splitList(node *head, node **evenHeadRef, node **oddHeadRef, int n)
{
    // there are 2 ptrs for even LL : head and tail
    node *evenHead = NULL;
    node *evenTail = NULL;
    // there are 2 ptrs for odd LL : head and tail
    node *oddHead  = NULL;
    node *oddTail  = NULL;
    // traversing through the main LL
    for (int i = 1; i <= n; i++, head = head -> next)
    {
        // when index is even
        if (i % 2 == 0)
        {
            // creating first node of even LL
            if (evenHead == NULL)
            {
                // let evenHead and evenTail point to head
                evenHead = head;
                evenTail = head;
            }
            // these are next nodes created after creation of first node of even LL
            else
            {
                // let evenTail -> next point head
                evenTail -> next = head;
                // updating evenTail
                evenTail = evenTail -> next;
            }
        }
        // when index is odd
        else
        {
            // creating first node of off LL
            if (oddHead == NULL)
            {
                // let oddHead and oddTail point to head
                oddHead = head;
                oddTail = head;
            }
            // these are next nodes created after creation of first node of odd LL
            else
            {
                // let oddTail -> next point head
                oddTail -> next = head;
                // updating oddTail
                oddTail = oddTail -> next;
            }
        }
    }
    // after creating of even LL and odd LL 
    // we should point the updated and final tails to NULL
    evenTail -> next = NULL;
    oddTail -> next = NULL;
    // value at evenHeadRef = evenHead(pointer)
    *evenHeadRef = evenHead;
    // value at oddHeadRef = oddHead(pointer)
    *oddHeadRef = oddHead;
}
void main()
{
    // inputing number of nodes
    int n;
    scanf("%d", &n);
    // creating head of main LL
    node *head = createNode(n);
    // printing main LL
    printf("Original linked list = ");
    printList(head);
    // creating head of even LL
    node *evenHead = NULL;
    // creating head of odd LL
    node *oddHead = NULL;
    // this function splits the main LL to odd LL and even LL
    // since we are passing address of pointers 
    // we should use double pointer as parameter
    splitList(head, &evenHead, &oddHead, n);
    // printing even LL
    printf("\nEven List = ");
    printList(evenHead);
    // printing odd LL
    printf("\nOdd List = ");
    printList(oddHead);
}