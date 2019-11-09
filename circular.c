#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct list{
	int value;
	struct list *next;
}L;
//Function Prototype
void create(L *);
void display(L *);
void insert(L *);
void insert_anypos(L *);
void insert_before(L *);
void insert_beg(L *);
void delete(L * ,int );


L *head = NULL;
int main()
{
	int op,val;
	system("cls");
	while(1)
	{
		printf("\nEnter 1->Create\nEnter 2->Dispaly\nEnter 3->Insert End\nEnter 4->Insert any position\nEnter 5->Insert before\nEnter 7->Exit\nENter the operations : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(!head)
					create(head);
				else
					printf("\nLinked list is not empty.");
				break;
			case 2:
				display(head);
				break;
			case 3:
				insert(head);
				break;
			case 4:
				insert_anypos(head);
				break;
			case 5:
				insert_before(head);
				break;
			case 6:
				printf("\nEnter value to delete from Linked list : ");
				scanf("%d",&val);
				delete(head,val);
				break;
			case 7:
			printf("\nENd of program.");
				exit(0);
		}
		printf("\nEnter any key to continue : ");
		getch();
		system("cls");
	}
	return 0;
}

void create(L *ptr)
{
	char ch;
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	if(ptr==NULL)
		head = new_node;
	else
		ptr->next = new_node;
	new_node->next = head;
	printf("\nAre you want to insert new node : ");
	scanf(" %c",&ch);
	if(ch=='y' || ch=='Y')
		create(new_node);
}

void display(L *ptr)
{
	if(!ptr){
		printf("\nLinked List is empty.");
		return;
	}
	do{
		printf("%d->",ptr->value);
		ptr = ptr->next;
	}while(ptr!=head);
	printf("head");
}

void insert(L *ptr)
{
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	if(ptr==NULL)
	{
		head = new_node;
		new_node->next = head;
		return;
	}
	while(ptr->next!=head)
		ptr = ptr->next;
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void insert_anypos(L *ptr)
{
	if(!ptr)
	{
		printf("\nCircular linked list is empty.");
		return;
	}
	int val;
	printf("\nEnter value after which you want to insert : ");
	scanf("%d",&val);
	if(ptr->value==val)
	{
		L *new_node = (L *)malloc(sizeof(L));
		printf("\nEnter the value of new node : ");
		scanf("%d",&new_node->value);
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
	ptr = ptr->next;
	while(ptr!=head && ptr->value!=val)
		ptr = ptr->next;
	if(ptr==head){
		printf("\nValue not founded in linked list.");
		return;
	}
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void insert_beg(L *ptr)
{
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	while(ptr->next!=head)
		ptr = ptr->next;
	new_node->next = ptr->next;
	ptr->next = new_node;
	head = new_node;
}
void insert_before(L *ptr)
{
	int val;
	printf("\nENter the value before which you want to insert : ");
	scanf("%d",&val);
	if(ptr==NULL)
		return;
	if(ptr->value==val)
		insert_beg(head);
	L *ptr1 = ptr->next;
	while(ptr1!=head)
	{
		if(ptr1->value == val)
		{
			L *new_node = (L *)malloc(sizeof(L));
			printf("\nEnter the value of new node : ");
			scanf("%d",&new_node->value);
			new_node->next = ptr->next;
			ptr->next = new_node;
		}
		ptr = ptr1;
		ptr1 = ptr1->next;
	}

}


void delete(L *ptr,int val)
{
	L *loc;
	if(ptr==NULL)
		return;
	if(ptr->value==val && ptr->next==head)
	{
		loc = head;
		head = NULL;
		free(loc);
		return;
	}
	if(ptr->value==val)
	{
		loc = ptr;
		while(ptr->next!=head)
			ptr = ptr->next;
		ptr->next = ptr->next->next;
		head = head->next;
		free(loc);
		ptr = head;
		delete(head,val);
	}
	else
	{
		L *ptr1 = ptr->next;
		while(ptr1!=head)
		{
			if(ptr1->value==val)
			{
				loc = ptr1;
				ptr->next = ptr1->next;
				free(loc);
				ptr1 = ptr->next;
			}
			else
			{
				ptr = ptr1;
				ptr1 = ptr1->next;
			}
		}
	}
}