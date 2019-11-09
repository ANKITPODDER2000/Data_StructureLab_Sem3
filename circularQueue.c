#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insert(void);
void delete(void);
void display(void);

int *queue,rear=-1,front=-1,size;

int main()
{
	int op;
	system("cls");
	printf("\nEnter total no of Elements in Circular Queue : ");
	scanf("%d",&size);
	queue = (int *)malloc(sizeof(int)*size);
	while(1)
	{
		printf("\nEnter 1->Insert\nEnter 2->Delete\nEnter 3->Display\nEnter 4->Exit\nEnter the operation : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nEnd of the Program.");
				exit(0);
		}
		printf("\nEnter any key to Continue : ");
		getch();
		system("cls");
	}
}
void insert(void)
{
	if((rear==0 && front==size-1) || front+1==rear)
	{
		printf("\nQueue overflow.%d %d",rear,front);
		return;
	}
	if(rear==-1 && front==-1)
		rear++;
	else if(front==size-1)
		front = -1;
	printf("\nEnter the element to insert in Queue : ");
	++front;
	scanf("%d",queue+front);
}
void delete(void)
{
	if(rear==-1)
	{
		printf("\nQueue underflow.");
		return;
	}
	printf("\n%d is deleted properly.",queue[rear]);
	if(rear==front)
		rear=front=-1;
	else if(rear==size-1)
		rear = 0;
	else
		rear++;
}
void display(void)
{
	int i;
	//printf("%d====%d",front,rear);
	if(rear==-1)
	{
		printf("\nQueue Underflow.");
		return;
	}
	printf("\nQueue is : ");
	if(front>=rear)
	{
		for(i=rear;i<=front;i++)
			printf("%d ",*(queue+i));
	}
	else{
		for(i=0;i<=front;i++)
			printf("%d ",*(queue+i));
		for(i=rear;i<size;i++)
			printf("%d ",*(queue+i));	
	}
}