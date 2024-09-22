#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=0, rear=-1;

int enqueue(int a)
{
	queue[++rear]=a;
	if (rear==MAX-1)
	printf("Overflow");
}

int dequeue()
{
	return queue[front++];
	if (rear==front-1)
	{
		rear=-1;
		front=0;
	}
	if (front==0)
	printf("Underflow");
}

int main()
{
	int c, ele;
	while (c!=4)
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Choice: ");
		scanf("%d", &c);
		
		switch(c)
		{
			case 1:
			printf("Enter the Element: ");
			scanf("%d", &ele);
			enqueue(ele);
			break;
			
			case 2:
			printf("%d\n", dequeue());
			break;
			
			case 3:
			for(int i=front; i<=rear; i++)
			{
				printf("%d\n", queue[i]);
			}
			break;
			
			case 4:
			break;
			
			default:
			printf("Invalid Input");
		}
	}
}
