/* 1) In mahematics, a polynomial is an expressionons consisting of indeterminates(also called
variables) and coefficients,that involves only the operations of addition, subtraction,
multiplication, and positive-integer powers of variables. An example of a polynomial of a
single variable x is: x
2−4x+7.
Such polynomials can be represented in computer memory using singly linked list.
Write function based C code for the following:
a) To create a node to store polynomial term of one variable.
b) To insert a node at sorted position based on power of a polynomial term.
c) To merge two polynomials.
d) To display a polynomial                   */
#include <stdio.h>
#include <stdlib.h>

struct polynomial{
    int coeff, power;
    struct polynomial *next;
};


//FUNCTION TO CREATE THE POLYNOMIAL
struct polynomial * create_poly(struct polynomial k){
    
    struct polynomial *head;
    head = ( struct polynomial *)malloc( sizeof(struct polynomial));
    
    head->coeff = k.coeff;
    head->power = k.power;
    head->next = NULL;
    
    return head;
}


//FUNCTION TO INSERT THE TERM IN POLYNOMIAL
struct polynomial * insert_poly( struct polynomial *head, struct polynomial k){
    
    struct polynomial *new, *temp;
    temp = head;
    new = ( struct polynomial *)malloc(sizeof(struct polynomial));
    new->coeff = k.coeff;
    new->power = k.power;
    
    if( temp->power < k.power){
        new->next = head;
        return new;
    }
    else{
        while(temp->next != NULL || temp->power < k.power){
            temp = temp->next;
        }
        if(temp->next == NULL){
            temp->next = new;
            new->next = NULL;
            
            return head;
        }
        if( temp->power < k.power){
            new->next = temp->next;
            temp->next = new;
            
            return head;
        }
    }
}


//FUNCTION TO OBTAIN THE POLYNOMIAL
struct polynomial * get_poly( struct polynomial *head){
    
    struct polynomial k;
    char x;
    
    while(1){
        
        printf("\nEnter the coefficient and power of the polynomial of the format {coefficient, power} : ");
        scanf("%d,%d", &k.coeff, &k.power);
        
        if(head == NULL)
            head = create_poly( k);
        else
            head = insert_poly(head, k);    
            
        fflush(stdout);
        printf("\nDo you want to enter the another term {Y/N} : ");
        getchar();
        scanf("%c", &x);
        
        if(x == 'N' || x == 'n')
            break;
    }
    
    return head;
    
}


//FUNCTION TO DISPLAY POLYNOMIAL FUNCTION 
void display( struct polynomial *head) {
    
    while(head != NULL){
        printf(" %dx%d ", head->coeff, head->power);
        
        if(head->next == NULL)
            break;
            
        head = head->next;
        printf("+");
    }
}


//FUNCTION TO INPUTING THE RESULTANT POLYNOMIALS
struct polynomial * input_poly( struct polynomial k, struct polynomial *head){
    if(head == NULL)
        head = create_poly(k);
    else
        head = insert_poly(head, k);
    
    return head;
}


//FUNCTION FOR MERGING THE POLYNOMIALS
struct polynomial * merge_poly( struct polynomial *head1, struct polynomial *head2, struct polynomial *res_head){
    
    struct polynomial k;
    
    while( head1 != NULL && head2 != NULL){//WHEN BOTH THE POLYNOMIALS ARE NOT NULL
        
        if(head1->power > head2->power){
            k.power = head1->power;
            k.coeff = head1->coeff;
            
            res_head = input_poly(k, res_head);

            head1 = head1->next;
            continue;
        }
        else if(head1->power < head2->power){
                k.power = head2->power;
                k.coeff = head2->coeff;
                
                res_head = input_poly(k, res_head);
                
                head2 = head2->next;
                continue;
        }
        else if( head1->power == head2->power){
                k.power = head2->power;
                k.coeff = head2->coeff + head1->coeff;
                
                res_head = input_poly(k, res_head);
                
                head1 = head1->next;
                head2 = head2->next;
                continue;
        }
        
    }
    
    while(head1 != NULL && head2 == NULL){
            k.power = head1->power;
            k.coeff = head1->coeff;
            
            res_head = input_poly(k, res_head);

            head1 = head1->next;
    }
    
    while(head2 != NULL && head1 == NULL){
            k.power = head2->power;
            k.coeff = head2->coeff;
            
            res_head = input_poly(k, res_head);

            head2 = head2->next;
    }
    
    return res_head;
}


int main()
{
    struct polynomial *poly1, *poly2 = NULL, *res_poly = NULL;
    poly1 = NULL;
    
    printf("Enter the first polynomial \n");
    poly1 = get_poly(poly1);
    printf("Enter the second polynomial \n");
    poly2 = get_poly(poly2);
    
    printf("\nThe first polynomial :\n");
    display(poly1);
    printf("\nThe second polynomial :\n");
    display(poly2);
    
    printf("\nThe resultant polynomial is \n");
    res_poly = merge_poly( poly1, poly2, res_poly);
    display(res_poly);

    return 0;
}