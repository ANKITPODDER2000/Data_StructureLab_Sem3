#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct list{
	int value;
	struct list *next;
}Queue;

void insert(Queue *);
void delete(void);
void display(Queue *);

Queue *head=NULL;

int main()
{
	int op;
	system("cls");
	while(1)
	{
		printf("\nEnter 1->Insert\nEnter 2->Delete\nEnter 3->Display\nEnter 4->Exit\nEnter the operation : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				insert(head);
				break;
			case 2:
				delete();
				break;
			case 3:
				display(head);
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

void insert(Queue *ptr)
{
	Queue *new_node = (Queue *)malloc(sizeof(Queue));
	new_node->next = NULL;
	printf("\nEnter the value of new Node : ");
	scanf("%d",&new_node->value);
	if(ptr==NULL)
	{
		head = new_node;
		return;
	}
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = new_node;
}
void delete(void)
{
	Queue *loc;
	if(!head)
	{
		printf("\nQueue underflow.");
		return;
	}
	printf("\n%d is deleted properly.",head->value);
	if(head->next==NULL)
	{
		loc = head;
		head = head->next;
		free(loc);
		return;
	}
	loc = head;
	head = head->next;
	free(loc);
}
void display(Queue *ptr)
{
	if(!ptr)
	{
		printf("\nQueue Underflow.");
		return;
	}
	printf("\nQueue is : ");
	while(ptr)
	{
		printf("%d",ptr->value);
		ptr = ptr->next;
	}
}