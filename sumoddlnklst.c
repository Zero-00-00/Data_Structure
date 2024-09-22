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
        node* head = NULL;
        int n;
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        append(&head);
        //summation of odd numbers
        node* t1=head;
        int s=0;
        while(t1->next!=NULL)
        {
            int d=t1->data;
            if(d%2!=0)
            s+=d;
            t1=t1->next;
        }
        printf("The Summatiojn of the odd numbers: %d", s);
    }