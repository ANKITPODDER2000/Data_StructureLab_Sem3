//===============================Linear Search===============================//
#include <stdio.h>
#include <stdlib.h>

//Function Prototype
void input(void);
void display(void);
void search(void);

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
	int key;
	printf("\nEntre key to search : ");
	scanf("%d",&key);
	for(int i=0;i<size;i++)
	{
		if(arr[i]==key){
			printf("\nKey found.");
			return;
		}
	}
	printf("\nKey not found.");
}