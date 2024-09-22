#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

int top=-1;
int stack[MAX_SIZE];
char post[MAX_SIZE];

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

char pop()
{
	if (top==-1)
	{
		//printf("\nStack Underflow\n\n");
		//return 'e';
	}
	else
	{
		return stack[top--];
		//printf("\nPopped\n\n");
	}
}

int prcd(char op1, char op2)
{
	if (op1=='(' || op1==')' || op2=='(' || op2==')')
	{
		if (op1=='(' && (op2!='(' || op2!=')'))
		return 0;
		else if (op1!='(' && op2=='(')
		{
			if (op1==')')
			return 1;
			else
			return 0;
		}
		else if (op1!=')' && op2==')')
		{
			if (op1=='(')
			return 0;
			else
			return 1;
		}
	}
	else
	{
		if (op1=='/')
		op1='*';
		if (op2=='/')
		op2='*';
		if (op1=='-')
		op1='+';
		if (op2=='-')
		op2='+';
	
		char op[]={'$','*','+'};
		for(int i=0; i<3; i++)
		{
			if (op1==op[i])
			op1=i;
		if (op2==op[i])
			op2=i;
		}
	
		if (op1<=op2)
		return 1;
		else
		return 0;
	}
}

void in_post(char *inp)
{
	char *p=inp;
	char topsym;
	while (*p!='\0')
	{
		char sym=*p;
		if (sym=='+'||sym=='-'||sym=='*'||sym=='/'||sym=='$'||sym=='('||sym==')')
		{
			while(top!=-1 && prcd(stack[top], sym))
			{
				topsym=pop();
				strncat(post, &topsym, 1);
			}
			push(sym);
		}
		else
		{
			strncat(post, &sym, 1);
		}
		
		if (stack[top]==')')
		{
			while(stack[top]!='(')
			{
				pop();
			}
			pop();
		}
		++p;
	}
	while(top!=-1)
	{
		topsym=pop();
		strncat(post, &topsym, 1);
	}
}

void main()
{
	char inp[MAX_SIZE+1];
	printf("Enter the Infix Expression: \n");
	scanf("%s", inp);
	in_post(inp);
	printf("\nThe Postfix Expression:\n");
	for(int i=0;post[i]!='\0';i++)
	{
		printf("%c", post[i]);
	}
	printf("\n");
}
