#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insert_rear(void);
void insert_front(void);
void delete_front(void);
void delete_rear(void);
void display(void);

int *a,front=-1,rear=-1,size;
int main()
{
	int op;
	printf("\nEnter max size of Dequeue : ");
	scanf("%d",&size);
	a = (int *)malloc(sizeof(int)*size);
	while(1)
	{
		printf("\nEnter 1->Input Restricted\nEnter 2->Output Restricted\nEnter 2->Exit\nEnter the operation : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				do{
					printf("\nEnter 1->Input\nEnter 2->Delete Front\nEnter 3->Delete Rear\nEnrter 4->Display\nENter 5->Break\nEnter the operation : ");
					scanf("%d",&op);
					switch(op){
						case 1:
							insert_front();
							break;
						case 2:
							delete_front();
							break;
						case 3:
							delete_rear();
							break;
						case 4:
							display();
							break;
						case 5:
							break;
						default :
							printf("\nWrong input Try again.");
							break;
					}
					printf("\nEnter any Key to Continue : ");
					getch();
					system("cls");
				}while(op!=5);
			case 2:
				do{
					printf("\nEnter 1->Insert rear\nEnter 2->Insert Front\nEnter 3->Delete\nEnrter 4->Display\nENter 5->Break\nEnter the operation : ");
					scanf("%d",&op);
					switch(op){
						case 1:
							insert_rear();
							break;
						case 2:
							insert_front();
							break;
						case 3:
							delete_rear();
							break;
						case 4:
							display();
							break;
						case 5:
							break;
						default :
							printf("\nWrong input Try again.");
							break;
					}
					printf("\nEnter any Key to Continue : ");
					getch();
					system("cls");
				}while(op!=5);
			case 3:
				printf("\nENd of Program.");
				exit(0);
		}
		printf("\nEnter any Key to Continue : ");
		getch();
		system("cls");
	}
}
void insert_rear(void)
{
	if((rear==0 && front==size-1) || front+1==rear)
	{
		printf("\nQueue overflow.%d %d",rear,front);
		return;
	}
	if(rear==-1 && front==-1)
		front=rear=0;
	else if(rear==0)
		rear = size-1;
	else
		rear--;
	printf("\nEnter the value to insert at rear Position : ");
	scanf("%d",a+rear);
}
void insert_front(void)
{
	if((rear==0 && front==size-1) || front+1==rear)
	{
		printf("\nQueue overflow.%d  %d",rear,front);
		return;
	}
	if(rear==-1 && front==-1)
		front=rear=0;
	else if(front==size-1)
		front = 0;
	else
		front++;
	printf("\nEnter the value to insert at rear Position : ");
	scanf("%d",a+front);
}
void delete_front(void)
{
	if(rear==-1)
	{
		printf("\nQueue underflow.");
		return;
	}
	printf("\n%d is deleted properly.",a[front]);
	if(rear==front)
		rear=front=-1;
	else if(front==0)
		front = size-1;
	else
		front--;
}
void delete_rear(void)
{
	if(rear==-1)
	{
		printf("\nQueue underflow.");
		return;
	}
	printf("\n%d is deleted properly.",a[rear]);
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
			printf("%d ",*(a+i));
	}
	else{
		for(i=0;i<=front;i++)
			printf("%d ",*(a+i));
		for(i=rear;i<size;i++)
			printf("%d ",*(a+i));	
	}
}