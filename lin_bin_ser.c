#include <stdio.h>

void selectionsort(int arr[], int n)
{
	int key;
	for (int i=0; i<n-1; i++)
	{
		key=i;
		for(int j=i+1; j<n; j++)
		{
			if (arr[key]>arr[j])
			{
				key=j;
			}
		}
		if (i!=key)
		{
			int temp=arr[i];
			arr[i]=arr[key];
			arr[key]=temp;
		}
	}
}

void linear(int arr[], int n, int find)
{
	int i=0, found=0;
	for (i=0; i<n; i++)
	{
		if (arr[i]==find)
		{
			found=1;
			break;
		}
	}
	if (found!=0)
	printf("Found %d at %d", find, i+1);
	else
	printf("Not Found");
}

void binary(int arr[], int n, int find)
{
	int low=0, high=n-1, mid=0, found=0;
	while (low <= high)
	{
        	mid = low + (high - low) / 2;
	        if (arr[mid] == find) 
	        { 	
	        	found=1;
			break;
	        }
        	else if (arr[mid] < find) 
        	{
            		low = mid + 1; // Continue searching in the right half
        	}
        	else 
        	{
            		high = mid - 1; // Continue searching in the left half
        	}
    	}
    	if (found!=0)
    	printf("Found %d at %d\n", find, mid+1);
	else
	printf("Not Found\n");
    
}

int main()
{
	int n, find;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];
	//creating array
	printf("Enter the elements: \n");
	for (int i=0; i<n; i++)
	{
		scanf("%d", &(arr[i]));
	}
	printf("Enter the element you want to find: ");
	scanf("%d", &find);
	//sorting
	selectionsort(arr, n);
	//printing
	printf("The Sorted Array: \n");
	for (int i=0; i<n; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	//searching
	printf("Linear Search: \n");
	linear(arr, n, find);
	printf("\nBinary Search: \n");
	binary(arr, n, find);
}
