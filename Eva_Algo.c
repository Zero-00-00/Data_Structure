#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 50

int top=-1;
int stack[MAX_SIZE];

int push(int ele)
{
	if (top==MAX_SIZE-1)
	{
		printf("\nStack Overflow\n\n");
	}
	else
	{
		stack[++top]=ele;
		//printf("\nPushed %d\n\n", ele);
	}
}

int pop()
{
	if (top==-1)
	{
		printf("\nStack Underflow\n\n");
		return -1;
	}
	else
	{
		return stack[top--];
		//printf("\nPopped\n\n");
	}
}

int eva_algo(char* inp)
{
	char *p=inp;
	while (*p!='\0')
	{
		char sym=*p;
		int value;
		if (sym=='+'||sym=='-'||sym=='*'||sym=='/'||sym=='$')
		{
			int op2=pop();
			int op1=pop();
			switch (sym)
			{
				case '+':
				value=op1+op2;
				break;
				
				case '-':
				value=op1-op2;
				break;
					
				case '*':
				value=op1*op2;
				break;
					
				case '/':
				value=op1/op2;
				break;
					
				case '$':
				value=(int)pow(op1, op2);
				break;
			}
			push(value);
		}
		else
		{
			int op=sym-'0'; //convert char to str
			push(op);
		}
		++p;
	}
	return pop();
}

int main()
{
	char inp[MAX_SIZE+1];
	printf("Enter the Postfix Expression: \n");
	scanf("%s", inp);
	printf("The result: %d\n", eva_algo(inp));
}
