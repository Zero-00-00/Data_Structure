//Deletion

#include <stdio.h>

void main()
{
	int len, pos;
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
	printf("Enter the positon you want to delete: ");
	scanf("%d", &pos);
	if (pos<=len)
	{
		for (int i=pos-1; i<len; i++)
		{
			arr[i]=arr[i+1];
		}
	
		printf("\nThe New Array: \n");
		for (int i=0; i<len-1; i++)
		{
			printf("%d\n", arr[i]);
		}
	}
	else
	printf("Index out Bounce\n");
}
