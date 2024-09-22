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
    {
        t1->next=t1;
        *head=t1;
    }
    else
    {
        t2=*head;   
        t1->next=t2->next;
        t2->next=t1;
        *head=t1;
    }
    printf("%d is successfully appended\n", x);
}

void in_fnt(node **head)
{
    node* t1, *t2;
    int x;
    printf("Enter the data you want to append: ");
    scanf("%d", &x);
    t1= (node*) malloc(sizeof(node*));
    t1->data=x;
    t1->next=NULL;
    if (*head==NULL)
    {
        t1->next=t1;
        *head=t1;
    }
    else
    {
        t2=*head;
        t1->next=t2->next;
        t2->next=t1;
    }
    printf("%d is successfully inserted in front\n", x);
}

void print(node **head)
{
    node *t;
    t=*head;
    do {
        printf("%d\n", t->data);
        t = t->next;
    } while (t != *head);
}

int main()
    {
        node* head=NULL;
        int c=0;
        while(c!=4)
        {
            printf("1.Append\n2.Insert at begining\n3.Dispaly\n4.Exit\nEnter your choice: ");
            scanf("%d", &c);
            switch(c)
            {
                case 1:
                append(&head);
                break;
                case 2:
                in_fnt(&head);
                break;
                case 3:
                print(&head);
                break;
                case 4:
                break;
                default:
                printf("Invalid Choice\n");
            }
        }
    }