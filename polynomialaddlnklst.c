#include <stdio.h>
    #include <stdlib.h>

    typedef struct lnk
    {
        int data;
        struct lnk* next;
    }node;

    void append(node **head)
    {
        node* t1, *t2;
        int x;
        printf("Enter the data you want to append: ");
        scanf("%d", &x);
        t1= (node*) malloc(sizeof(node*));
        t1->data=x;
        t1->next=NULL;
        if (*head==NULL)
        *head=t1;
        else
        {
            t2=*head;
            while(t2->next!=NULL)
            {
                t2=t2->next;
            }
            t2->next=t1;
        }
        printf("%d is successfully appended\n", x);
    }

    int main()
    {
        node* head1=NULL;
        node* head2=NULL;
        int n;
        printf("Enter the degree of the polynomials: ");
        scanf("%d", &n);
        //first polynomial
        for(int i=0; i<n; i++)
        {
            printf("Enter the coefficient of power %d", n-i);
            append(&head1);
        }
        //Second polynomial
        for(int i=0; i<n; i++)
        {
            printf("Enter the coefficient of power %d", n-i);
            append(&head2);
        }
        //calculation
        node* t1=head1;
        node* t2=head2;
        while(t1->next!=NULL&&t2->next!=NULL)
        {
            int x, y;
            x=t1->data;
            y=t2->data;
            printf("%d is the coefficient of power %d", x+y, n);
            n--;
        }

    }