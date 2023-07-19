/* Q2) Write a C program to create a linked list. Split the created list into two lists: one
containing the elements of even indices, other containing elements of odd indiced the original list
(Menu Driven) */
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
void createNode(node **head, int newData)
{
    node* newNode = (node*) malloc (sizeof(node));
    newNode -> data = newData;
    newNode -> next = *head;
    *head = newNode;
}
// this function splits the main LL to odd LL and even LL
// since we are passing address of pointers 
// we should use double pointer as parameter
void splitList(node *head, node **evenHeadRef, node **oddHeadRef)
{
    // there are 2 ptrs for even LL : head and tail
    node *evenHead = NULL;
    node *evenTail = NULL;
    // there are 2 ptrs for odd LL : head and tail
    node *oddHead  = NULL;
    node *oddTail  = NULL;
    // traversing through the main LL
    for (int i = 1; head != NULL; i++, head = head -> next)
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
    node *head = NULL;
    node *evenHead = NULL;
    node *oddHead = NULL;
    int choice;
    int data;
    do 
    {
        printf("\n1. Add node to linked list\n");
        printf("2. Print linked list\n");
        printf("3. Split linked list into even and odd index lists\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:  {
                         printf("Enter data to add to linked list: ");
                         scanf("%d", &data);
                         createNode(&head, data);
                     } 
                     break;
            case 2:
                printList(head);
                break;
            case 3:
                splitList(head, &evenHead, &oddHead);
                printf("Even index linked list: ");
                printList(evenHead);
                printf("Odd index linked list: ");
                printList(oddHead);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
}