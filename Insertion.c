//Insertion

#include <stdio.h>

void main()
{
	int len, ele, pos;
	printf("Enter the length of the array: ");
	scanf("%d", &len);
	int arr[len+1];
	
	printf("\nCreating Array...\n");
	for (int i=0; i<len; i++)
	{
		printf("Enter Element %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\nThe Original Array: \n");
	for (int i=0; i<len; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	printf("\nInsertion Operation\n");
	printf("Enter the Element you want to insert: ");
	scanf("%d", &ele);
	printf("Enter the position you want to enter the element: ");
	scanf("%d", &pos);
	if (pos<=len)
	{
		for (int i=len-1; i>=pos-1; i--)
		{
			arr[i+1]=arr[i];
		}
		arr[pos-1]=ele;
	
		printf("\nThe New Array: \n");
		for (int i=0; i<len+1; i++)
		{
			printf("%d\n", arr[i]);
		}
	}
	else
	printf("Index out Bounce\n");
}
