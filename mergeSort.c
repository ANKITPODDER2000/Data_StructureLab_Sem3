#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void input(void);
void display(void);
void part(int *,int ,int );
void merge(int *,int ,int ,int );

int size,*arr;

int main()
{
	printf("\nEnter total number of element : ");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	input();
	printf("\nArray is : ");
	display();
	part(arr,0,size-1);
	printf("\nSorted Array is : ");
	display();
	return 0;
}
void input()
{
	printf("\nENtre all array elements : ");
	int i;
	for(i=0;i<size;i++)
		scanf("%d",arr+i);
}
void display()
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",*(arr+i));
}
void part(int *a,int l,int u)
{
	if(u>l){
		int mid = (u+l)/2;
		part(a,l,mid);
		part(a,mid+1,u);
		merge(a,l,mid,u);
	}
}
void merge(int *a,int l,int mid,int u)
{
	int *temp = (int *)malloc(sizeof(int) * (u-l+1));
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=u)
	{
		if(*(a+i) > *(a+j))
		{
			*(temp+k) = *(a+j);
			j++;
		}
		else{
			*(temp+k) = *(a+i);
			i++;
		}
		k++;
	}
	if(j>u)
	{
		while(i<=mid)
		{
			*(temp+k) = *(a+i);
			i++;
			k++;
		}
	}
	if(i>mid)
	{
		while(j<=u)
		{
			*(temp+k) = *(a+j);
			j++;
			k++;
		}
	}
	for(i=l;i<=u;i++)
		*(a+i) = *(temp+i);
}