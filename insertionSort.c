//===============================Insertion Sort===============================//
#include <stdio.h>
#include <stdlib.h>

//Function Prototype
void input(void);
void display(void);
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
	printf("\nSorted Array is : ");
	display();
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