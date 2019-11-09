#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void push(void);
void pop(void);
void display(void);
int *stack,top=-1,size;

int main()
{
	system("cls");
	int op;
	printf("\nEnter max size of Stack : ");
	scanf("%d",&size);
	stack = (int *)malloc(sizeof(int));
	while(1)
	{
		printf("\nEnter 1->Push\nEnter 2->Pop\nEnter 3->Display\nEnter 4->Exit\nENter the operation : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nEnd of the Program.");
				exit(0);
			default:
				printf("\nWrong input try Again");
				break;
		}
		printf("\nEnter any key to Contionue : ");
		getch();
		system("cls");
	}
	return 0;
}
void push(void)
{
	if(top==size-1)
	{
		printf("\nStack Overflow.");
		return;
	}
	++top;
	printf("\nEnter the Array element : ");
	scanf("%d",stack+top);
}
void pop(void)
{
	if(top==-1)
	{
		printf("\nStack underflow.");
		return;
	}
	printf("\n%d is removed properly.",*(stack+top));
	--top;
}
void display(void)
{
	int i;
	if(top==-1)
	{
		printf("\nStack underflow.");
		return;
	}
	printf("\nSatck elements are : ");
	for(i=0;i<=top;i++)
		printf("%d ",*(stack+i));
}