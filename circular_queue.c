 #include <stdio.h>
#define MAX 5

int queue[MAX], rear=-1, front=0, k=0;

int enqueue(int a)
{
    if (rear==MAX-1 && front!=0)
    {
        rear=0;
        queue[rear]=a;
    }
    else
    queue[++rear]=a;
    if (rear==front-1 || (rear==MAX-1 && front==0))
    printf("Overflow\n");
    
}

int dequeue()
{
    if (front==MAX-1 && rear!=0)
    {
        front=0;
        return queue[front];
    }
    else
    k=queue[front];
    queue[front++]=0;
    if (front==rear-1 || (front==MAX-1 && rear==0))
    printf("Underflow\n");
    return k;
}

int main()
{
    int c, ele;

    while(c!=4)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
            printf("Enter the element you want to enter: ");
            scanf("%d", &ele);
            enqueue(ele);
            break;

            case 2:
            printf("%d\n", dequeue());
            break;

            case 3:
            for(int i = 0;i<MAX;i++){
            printf("%d \n",queue[i]);
            }
            break;

	case 4:
	break;
	
            default:
            printf("Invalid Input");
        }
    }
}
