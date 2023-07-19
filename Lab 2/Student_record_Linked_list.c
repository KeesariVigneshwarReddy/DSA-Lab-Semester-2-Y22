/* 
1) Write a function based C program for the following purpose:
a) To read student records from a file.
b) To create a singly list of students.
c) To split this linked list on the basis of their branch.
d) To display a linked list  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int roll;
    char name[50], branch[10];
};

struct stu_node{
    struct student x;
    struct stu_node *next;
};


//FUNCTION FOR CREATING A LINKED LIST
struct stu_node * create_node(struct student k){
    
    struct stu_node *p;
    p = ( struct stu_node *)malloc( sizeof(struct stu_node));
    
    p->x.roll = k.roll;
    strcpy((p->x).name, k.name);
    strcpy((p->x).branch, k.branch);
    
    p->next = NULL;
    
    return p;
}


//FUNCTION TO DISPLAY LINKED LIST
void display( struct stu_node *head){
    
    int i = 1;
    while( head != NULL){

        printf("student no : %d\n\t",i++);
        printf("Roll : %d \t",head->x.roll);
        printf("Name : %s \t",(head->x).name);
        printf("Branch : %s\n",(head->x).branch);
            
        head = head->next;
        
    }
}


//FUNCTION TO INSERT THE STRUCTURE
void insert_node( struct stu_node *head, struct student k){
    
    while( head->next != NULL)
        head = head->next;
        
    struct stu_node *new;
    new = (struct stu_node *)malloc( sizeof(struct stu_node));
    
    new->x.roll = k.roll;
    strcpy((new->x).name,k.name);
    strcpy((new->x).branch,k.branch);
    
    new->next = NULL;
    head->next = new;
    
}


//FUNCTION TO SORT ACCORDING TO THE BRANCH
void branch_sorting( struct stu_node *head){
    
    struct stu_node *head_cse = NULL, *head_ece = NULL, *head_mec = NULL;
    struct student a;
    
    while( head != NULL){
        
        a.roll = head->x.roll;
        strcpy(a.name, (head->x).name);
        strcpy(a.branch, (head->x).branch);
    
        if( strcmp((head->x).branch,"CSE") == 0 ){
            if( head_cse == NULL)
                head_cse = create_node(a);
            else
                insert_node(head_cse, a);
        }
        else if( strcmp((head->x).branch,"ECE") == 0 ){
            if( head_ece == NULL)
                head_ece = create_node(a);
            else
                insert_node(head_ece, a);
        }
        else{
            if( head_mec == NULL)
                head_mec = create_node(a);
            else
                insert_node(head_mec, a);
        }
        
        head = head->next;
    }     //END OF while
    
    printf("\n\n*THE CSE STUDENTS**\n");
    display(head_cse);
    
    printf("\n\n*THE ECE STUDENTS**\n");
    display(head_ece);
    
    printf("\n\n*THE MEC STUDENTS**\n");
    display(head_mec);
    
}

int main()  //MAIN FUNCTION
{
    FILE *fs;
    fs = fopen("student.txt", "r");
    struct student st;
    struct stu_node *head = NULL;
    
    if( fs == NULL){
        printf("File not found");
        exit(0);
    }
    
    while(!feof(fs)){
        fscanf(fs,"%d, %[^,], %s", &st.roll, st.name, st.branch);
        
        if( head == NULL)
            head = create_node(st);
        else
            insert_node(head, st);
    }
    
    fclose(fs);
    
    printf("***STUDENT RECORD***\n");
    display(head);
    
    branch_sorting(head);
    
    return 0;
}