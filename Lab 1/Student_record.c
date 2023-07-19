/* 1) Define a structure Stud_Rec with members name, roll_number, branch, and 
marks. Write a C program to do the following.
a. Function Read_Rec ( ) to read the records of 5 students
b. Function Sort_Rec ( ) to sort records in chronological order and Write_Rec ( 
) to display sorted records.
c. Function Stud_Count ( ) to count and returns the number of students who has 
obtained at least above the threshold given by the user input.
d. main function that calls Read_Rec ( ), Sort_Rec ( ) and Stud_Count ( ) 
functions.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student records
struct Stud_Rec {
    char name[50];
    int roll_number;
    char branch[20];
    float marks;
};

// Function to read the records of n students
void Read_Rec(struct Stud_Rec *records, int n) {
    printf("Enter details of %d students:\n", n);
    for(int i=0; i<n; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", (records+i)->name);
        printf("Roll Number: ");
        scanf("%d", &(records+i)->roll_number);
        printf("Branch: ");
        scanf("%s", (records+i)->branch);
        printf("Marks: ");
        scanf("%f", &(records+i)->marks);
    }
}

// Function to sort records in chronological order
void Sort_Rec(struct Stud_Rec *records, int n) {
    struct Stud_Rec temp;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if((records+i)->roll_number > (records+j)->roll_number) {
                temp = *(records+i);
                *(records+i) = *(records+j);
                *(records+j) = temp;
            }
        }
    }
}

// Function to display sorted records
void Write_Rec(struct Stud_Rec *records, int n) {
    printf("\nSorted records of %d students:\n", n);
    printf("%-20s %-15s %-10s %-5s\n", "Name", "Roll Number", "Branch", "Marks");
    for(int i=0; i<n; i++) {
        printf("%-20s %-15d %-10s %-5.2f\n", (records+i)->name, (records+i)->roll_number, (records+i)->branch, (records+i)->marks);
    }
}

// Function to count the number of students who obtained marks above threshold
int Stud_Count(struct Stud_Rec *records, int n, float threshold) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if((records+i)->marks >= threshold) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    float threshold;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n student records
    struct Stud_Rec records = (struct Stud_Rec) malloc(n * sizeof(struct Stud_Rec));

    Read_Rec(records, n);
    Sort_Rec(records, n);
    Write_Rec(records, n);

    printf("\nEnter the threshold for marks: ");
    scanf("%f", &threshold);
    int count = Stud_Count(records, n, threshold);
    printf("\nNumber of students with marks above %.2f: %d\n", threshold, count);

    // Free the dynamically allocated memory
    free(records);
    return 0;
}