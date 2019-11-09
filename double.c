#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Structure
typedef struct dlist{
	int value;
	struct dlist *prev,*next;
}L;

//Function prototype

void create(L *);
void display(L *);
void insert_end(L *);
void insert_head(void);
void insert_anypos(L *);
void delete(L *,int );

L *head;

int main()
{
	system("cls");
	int op,val;
	head = (L *)malloc(sizeof(L));
	head->prev = NULL;
	printf("\nCreate Linked list first : ");
	create(head);
	printf("\nEnter any key to continue : ");
	getch();
	system("cls");
	while(1)
	{
		printf("\nEnter 1->Display\nEnter 2->Insert end\nEnter 3->Insert at Beginning\nEnter 4->Insert at Any possition\nEnter 5->Delete\n8->Exit\nEnter the operation : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				display(head);
				break;
			case 2:
				insert_end(head);
				break;
			case 3:
				insert_head();
				break;
			case 4:
				insert_anypos(head);
				break;
			case 5:
				printf("\nEnter value to delete : ");
				scanf("%d",&val);
				delete(head,val);
				break;
			case 8:
				printf("\nEnd of the program.\n");
				exit(0);
		}
		printf("\nEnter any key to continue : ");
		getch();
		system("cls");
	}
}

void create(L *ptr)
{
	char ch;
	printf("\nEnter ther value of node : ");
	scanf("%d",&ptr->value);
	ptr->next = NULL;
	printf("\nAre you want to insert a new node : ");
	scanf(" %c",&ch);
	if(ch=='Y' || ch=='y')
	{
		ptr->next = (L *)malloc(sizeof(L));
		ptr->next->prev = ptr;
		ptr = ptr->next;
		create(ptr);
	}
}
void display(L *ptr)
{
	if(!ptr)
	{
		printf("\nLinked list is empty.");
		return;
	}
	printf("\nLinked list is : ");
	while(ptr->next)
	{
		printf("%d->",ptr->value);
		ptr = ptr->next;
	}
	while(ptr)
	{
		printf("%d->",ptr->value);
		ptr = ptr->prev;
	}
	printf("NULL");
}

void insert_end(L *ptr)
{
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter value of new node to insert at end : ");
	scanf("%d",&new_node->value);
	if(!ptr)
	{
		new_node->next = new_node->prev = ptr;
		head = new_node;
		return;
	}
	while(ptr->next)
		ptr = ptr->next;
	new_node->prev = ptr;
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void insert_head(void)
{
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter value of new node to insert at end : ");
	scanf("%d",&new_node->value);
	if(!head)
	{
		new_node->next = new_node->prev = head;
		head = new_node;
		return;
	}
	new_node->prev = head->prev;
	new_node->next = head;
	head->prev = new_node;
	head = head->prev;
}

void insert_anypos(L *ptr)
{
	int val;
	if(!ptr)
	{
		printf("\nLinked list is empty");
		return;
	}
	printf("\nEnter value after which you wasnt to insert : ");
	scanf("%d",&val);
	while(ptr->next)
	{
		if(ptr->value==val)
		{
			L *new_node = (L *)malloc(sizeof(L));
			printf("\nEnter value of new node to insert after %d : ",val);
			scanf("%d",&new_node->value);
			new_node->prev = ptr;
			new_node->next = ptr->next;
			ptr->next->prev = new_node;
			ptr->next = new_node;
		}
		ptr = ptr->next;
	}
	if(ptr->value==val)
	{
		L *new_node = (L *)malloc(sizeof(L));
		printf("\nEnter value of new node to insert after %d : ",val);
		scanf("%d",&new_node->value);
		new_node->prev = ptr;
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}


void delete(L *ptr,int val)
{
	L *loc;
	if(ptr->next==NULL && ptr->value == val)
	{
		loc = ptr;
		free(loc);
		head = NULL;
		return;
	}
	if(ptr->value==val)
	{
		loc = ptr;
		ptr->next->prev = ptr->prev;
		head = head->next;
		free(loc);
		delete(head,val);
	}
	else
	{
		ptr = ptr->next;
		while(ptr->next)
		{
			if(ptr->value==val)
			{
				loc = ptr;
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			ptr = ptr->next;
			free(loc);
		}
		if(ptr->value==val)
		{
			ptr->prev->next = ptr->next;
			loc = ptr;
			free(loc);
		}
	}
}