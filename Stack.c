#include <stdio.h>
#define MAX_SIZE 5

int top=-1;
int stack[MAX_SIZE];

void push(int ele)
{
	if (top==MAX_SIZE-1)
	{
		printf("\nStack Overflow\n\n");
	}
	else
	{
		stack[++top]=ele;
		printf("\nPushed %d\n\n", ele);
	}
}

void pop()
{
	if (top==-1)
	{
		printf("\nStack Underflow\n\n");
	}
	else
	{
		stack[top--];
		printf("\nPopped\n\n");
	}
}

void display()
{
	for (int i=0; i<=top; i++)
	{
		printf("%d\n", stack[i]);
	}
	printf("\n");
}

void main()
{
	int c, ele;
	
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\nChoose: ");
		scanf("%d", &c);
		
		switch (c)
		{
			case 1:
			{
				printf("Enter the element you want to push: ");
				scanf("%d", &ele);
				push(ele);
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				printf("\n");
				display();
				break;
			}
			case 4:
			break;
			default:
			printf("\nInvalid Choice\n\n");
		}
		if (c==4)
		break;
	}
}
