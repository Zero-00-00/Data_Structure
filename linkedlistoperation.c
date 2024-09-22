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

    void in_fnt(node **head)
    {
        node* t1;
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
            t1->next=*head;
            *head=t1;
        }
        printf("%d is successfully inserted in front\n", x);
    }

    void insert(node **head)
    {
        node *t, *t1, *t2;
        int x, len=1, i=1, pos;
        t=*head;
        while(t->next!=NULL)
        {
            t=t->next;
            len++;
        }
        printf("Enter the positon at which you want to insert: ");
        scanf("%d", &pos);
        if (pos>len || pos<1)
        printf("Invalid Position\n");
        else
        {
            printf("Enter the data you want to insert: ");
            scanf("%d", &x);
            t1=(node*)malloc(sizeof(node*));
            t1->data=x;
            t1->next=NULL;
            t2=*head;
            while(i!=pos-1)
            {
                t2=t2->next;
                i++;
            }
            t1->next=t2->next;
            t2->next=t1;
            printf("%d successfully inserted at position %d\n", x, pos);
        }
    }

    void delete(node **head)
    {
        node *t, *t1, *t2;
        int len=1, i=1, pos;
        t=*head;
        while(t->next!=NULL)
        {
            t=t->next;
            len++;
        }
        printf("Enter the position at which you want to delete: ");
        scanf("%d", &pos);
        if (pos>len || pos<1)
        printf("Invalid Position\n");
        else
        {
            t1=*head;
            t2=t1->next;
            if (t1->next==NULL)
            {
                printf("Only one element can not delete\n");
                return;
            }
            if  (pos==1)
            {
                *head=t2;
                free(t1);
            }
            else
            {
                while(i!=pos-1)
                {
                    t1=t1->next;
                    t2=t1->next;
                }
                t1->next=t2->next;
                free(t2);
            }
            printf("Deletion Successful\n");
        }
    }

    void print(node* head)
    {
        printf("Printing the linked list\n");
        while(head!=NULL)
        {
            printf("%d\n", head->data);
            head=head->next;
        }
    }

    int main()
    {
        node* head=NULL;
        int c=0;
        while(c!=6)
        {
            printf("1.Append\n2.Insert at begining\n3.Insert\n4.Delete\n5.Print\n6.Exit\nEnter your choice: ");
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
                insert(&head);
                break;
                case 4:
                delete(&head);
                break;
                case 5:
                print(head);
                break;
                case 6:
                break;
                default:
                printf("Invalid Choice\n");
            }
        }
    }