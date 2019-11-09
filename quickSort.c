//===============================Quick Sort===============================//
#include <stdio.h>
#include <stdlib.h>

//Function Prototype
void input(void);
void display(void);
void sort(int *,int ,int );

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
	sort(arr,0,size-1);
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
void sort(int *a,int l,int h)
{
	if(h>l)
	{
		int temp,first=l+1,last=l+1;
		while(last<=h)
		{
			/*if(first==last)
			{
				if(*(a+first)<*(a+l) && *(a+last)<*(a+l))
				{
					first++;
					last++;
				}
				else
					last++;
			}*/
			if(*(a+last)<*(a+l))
			{
				temp = *(a+first);
				*(a+first) = *(a+last);
				*(a+last) = temp;
				first++;
			}
			last++;
		}
		temp = a[l];
		a[l] = a[first-1];
		a[first-1] = temp;
		sort(a,l,first-2);
		sort(a,first,h);
	}
}