#include <stdio.h>

void main()
{
	//Sparse Matrix

	int x, y;
	printf("Enter the row column of the array: ");
	scanf("%d %d", &x, &y);
	int arr[x][y];
	
	printf("\nCreating Matrix...\n");
	for (int i=0; i<x; i++)
	{
		for (int j=0; j<y; j++)
		{
			printf("Enter Element positon(%d, %d): ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	
	printf("\nThe Sparse Matrix: \n");
	for (int i=0; i<x; i++)
	{
		for (int j=0; j<y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	//Triplet
	
	int count=0, row=1;
	
	for (int i=0; i<x; i++)
	{
		for (int j=0; j<y; j++)
		{
			if (arr[i][j]!=0)
			count++;
		}
	}
	
	int trip[3][count+1];
	
	trip[0][0]=x, trip[0][1]=y, trip[0][2]=count;
	
	for (int i=0; i<x; i++)
	{
		for (int j=0; j<y; j++)
		{
			if (arr[i][j]!=0)
			{
				trip[row][0]=i;
				trip[row][1]=j;
				trip[row][2]=arr[i][j];
				row++;
			}
		}
	}
	
	printf("\nThe Triplet: \n");
	for (int i=0; i<count+1; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%d ", trip[i][j]);
		}
		printf("\n");
	}
}
