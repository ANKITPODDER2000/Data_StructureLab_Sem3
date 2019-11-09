#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct stack{
	int value;
	struct stack *next;
}Stack;

void push(Stack *);
void pop(Stack *);
void display(Stack *);

Stack *head = NULL;

int main()
{
	int op;
	system("cls");
	while(1)
	{
		printf("\nEnter 1->Push\nEnter 2->Pop\nEnter 3->Display\nEnter 4->Exit\nENter the operation : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				push(head);
				break;
			case 2:
				pop(head);
				break;
			case 3:
				display(head);
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
void push(Stack *ptr)
{
	Stack *new_node = (Stack *)malloc(sizeof(Stack));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	if(!ptr)
	{
		new_node->next = ptr;
		head = new_node;
		return;
	}
	while(ptr->next)
		ptr = ptr->next;
	new_node->next = ptr->next;
	ptr->next = new_node;

}
void pop(Stack *ptr)
{
	Stack *loc;
	if(!ptr)
	{
		printf("\nStack underflow.");
		return;
	}
	if(ptr->next==NULL)
	{
		loc = ptr;
		printf("\n%d is removed properly.",ptr->value);
		free(loc);
		head = NULL;
		return;
	}
	while(ptr->next->next)
		ptr = ptr->next;
	loc = ptr->next;
	printf("\n%d is removed properly.",ptr->next->value);
	ptr->next = ptr->next->next;
	free(loc);
}
void display(Stack *ptr)
{
	if(!ptr)
	{
		printf("\nStack underflow.");
		return;
	}
	printf("\nSatck elements are : ");
	while(ptr)
	{
		printf("%d ",ptr->value);
		ptr = ptr->next;
	}
}