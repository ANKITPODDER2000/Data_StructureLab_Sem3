//===============================Binary Search===============================//
#include <stdio.h>
#include <stdlib.h>

//Function Prototype
void input(void);
void display(void);
void search(void);
void sort(void);

//Global variable Declare
int *arr,size;

int main()
{
	printf("\nEnter total number of element : ");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	input();
	printf("\nArray is : ");
	display();
	sort();
	search();
	return 0;
}

void input(void)
{
	printf("\nEntre all array elements : ");
	int i;
	for(i=0;i<size;i++)
		scanf("%d",arr+i);
}
void display(void)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",*(arr+i));
}
void search(void)
{
	int i=0,j=size-1,key,mid;
	printf("\nEntre key to search : ");
	scanf("%d",&key);
	while(i<=j)
	{
		mid = (i+j)/2;
		if(arr[mid]==key)
		{
			printf("\nKey found");
			return;
		}
		else if(arr[mid] > key)
			j = mid-1;
		else
			i = mid+1;
	}
	printf("\nKey not found.");
}
void sort(void)
{
	int temp,j;
	for(int i=1;i<size;i++)
	{
		temp = *(arr+i);
		j = i-1;
		while(*(arr+j)>temp && j>=0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[++j] = temp;
	}
}