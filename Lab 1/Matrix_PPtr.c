/*  2) Write a C program to do the following tasks: 
    a) Function readData ( ) to read 2D array.
    b) Function displayData ( ) to display 2D array.
    c) Function searchElem ( ) to search an element provided by the users and return 
       the element and it’s all locations.
    d) main function to call readData ( ), displayData ( ), and searchElem ( )
       function                                                                       */
#include <stdio.h>
#include <stdlib.h>
// a function which reads data in a matrix
void readData(int **ptr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", (*(ptr + i) + j));
        }
    }
    printf("\n");
}
// a function which displays data in matrix
void displayData(int **ptr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}
// a function which search Element and returns location
void searchElement(int **ptr, int n, int m, int key)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(*(ptr + i) + j) == key)
            {
                printf("Found\n");
                printf("i = %d\nj = %d", i, j);
                return;
            }
        }
    }
}
void main()
{
    // inputing no. of rows and no. of columns
    int n, m;
    scanf("%d %d", &n, &m);
    // creating a matrix using dynamic memory allocation
    int **ptr = (int **) malloc (n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(ptr + i) = (int *) malloc (m * sizeof(int));
    }
    // a function which reads data in a matrix
    readData(ptr, n, m);
    // a function which displays data in matrix
    displayData(ptr, n, m);
    // inputing key
    int key;
    scanf("%d", &key);
    // a function which search Element and returns location
    searchElement(ptr, n, m, key);
}