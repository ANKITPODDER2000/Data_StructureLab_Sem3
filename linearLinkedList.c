#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct list{
	int value;
	struct list *next;
}L;

// Function prototype
void create(L *);
void display(L *);
void insert(L *);
void insert_head(void);
void insert_anypos(L *);
void insert_before(L *);
void insert_mid(L *);
void delete(L *,int );
void reverse(L *);
void sort(L *);


L *head = NULL;
int main()
{
	int op,val;
	system("cls");
	while(1){
		printf("\nEnter 1->Create\nEnter 2->Insert\nEnter 3->Insert_head\nEnter 4->Insert_any_Position\nEnter 5->Insert_before\nEnter 6->Insert_middle\nEnter 7->Delete\nEnter 8->Reverse\nEnter 9->Sort\nEnter 10->Display\nEnter 11->Exit\nENter the Operation : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(head)
					printf("\nYou already created a Linked List.");
				else
					create(head);
				break;
			case 2:
				insert(head);
				break;
			case 3:
				insert_head();
				break;
			case 4:
				insert_anypos(head);
				break;
			case 5:
				insert_before(head);
				break;
			case 6:
				insert_mid(head);
				break;
			case 7:
				printf("\nENter value to delete : ");
				scanf("%d",&val);
				delete(head,val);
				break;
			case 8:
				reverse(head);
				break;
			case 9:
				sort(head);
				break;
			case 10:
				display(head);
				break;
			case 11:
				exit(0);
		}
		printf("\nEnter Any key to continue : ");
		getch();
		system("cls");
	}
}




void create(L *ptr)
{
	char ch;
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	if(ptr!=NULL)
		ptr->next = new_node;
	else
		head = new_node;
	new_node->next = NULL;
	printf("\nAre you want to insert a node : ");
	scanf(" %c",&ch);
	if(ch=='Y' || ch=='y')
		create(new_node);
}



void display(L *ptr)
{
	if(ptr==NULL)
	{
		printf("\nLinked list is Empty.");
		return;
	}
	printf("\nLinked list is : ");
	while(ptr){
		printf("%d->",ptr->value);
		ptr = ptr->next;
	}
	printf("NULL");
}


void insert(L *ptr)
{
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	if(ptr==NULL)
	{
		new_node->next = head;
		head = new_node;
		return;
	}
	while(ptr->next)
		ptr = ptr->next;
	new_node->next = ptr->next;
	ptr->next = new_node;
}


void insert_head(void)
{
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	new_node->next = head;
	head = new_node;
}


void insert_anypos(L *ptr)
{
	int val;
	printf("\nENter value after which you want to insert : ");
	scanf("%d",&val);
	while( ptr && ptr->value!=val)
		ptr = ptr->next;
	if(!ptr)
	{
		printf("\nValue not found.");
		return;
	}
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value of new node : ");
	scanf("%d",&new_node->value);
	new_node->next = ptr->next;
	ptr->next = new_node;
}


void insert_before(L *ptr)
{
	int val;
	if(!ptr){
		printf("\nLinked List is Empty.");
		return;
	}
	printf("\nEnter value to insert before : ");
	scanf("%d",&val);
	if(ptr->value == val)
	{
		insert_head();
		return;
	}
	L *ptr1 = ptr,*ptr2 = ptr->next;
	while(ptr2!=NULL && ptr2->value!=val)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	if(!ptr2)
	{
		printf("\nValue not found.");
		return;
	}
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value to insert before %d : ",val);
	scanf("%d",&new_node->value);
	ptr1->next = new_node;
	new_node->next = ptr2;
}


void insert_mid(L *ptr)
{
	if(!ptr){
		printf("\nLinked List is Empty.");
		return;
	}
	int val1,val2;
	printf("\nEnter the two values : ");
	scanf("%d%d",&val1,&val2);
	while(ptr->next!=NULL)
	{
		if(ptr->value == val1 && ptr->next->value == val2)
			break;
		ptr = ptr->next;
	}
	if(!ptr->next)
	{
		printf("\n%d and %d not found in Linked List.",val1,val2);
		return;
	}
	L *new_node = (L *)malloc(sizeof(L));
	printf("\nEnter the value to insert in between %d & %d: ",val1,val2);
	scanf("%d",&new_node->value);
	new_node->next = ptr->next;
	ptr->next = new_node;
}


void delete(L *ptr,int val)
{
	L *loc,*ptr1;
	if(!ptr)
		return;
	if(ptr->value==val)
	{
		loc = ptr;
		head = head->next;
		free(loc);
		if(head)
			delete(head,val);
		else
			return;
	}
	else{
		ptr1 = ptr;
		ptr = ptr->next;
		while(ptr)
		{
			if(ptr->value == val)
			{
				loc = ptr;
				ptr1->next = ptr->next;
				ptr = ptr1->next;
				free(loc);
			}
			else
			{
				ptr1 = ptr;
				ptr = ptr->next;
			}
		}
	}
}



void reverse(L *ptr)
{
	L *prev=NULL,*after=NULL,*current=ptr;
	while(current)
	{
		after = current->next;
		current->next = prev;
		prev = current;
		current = after;
	}
	head = prev;
}
void sort(L *ptr)
{
	int temp;
	L *ptr1;
	while(ptr)
	{
		ptr1 = ptr->next;
		while(ptr1)
		{
			if(ptr1->value < ptr->value)
			{
				temp = ptr1->value;
				ptr1->value = ptr->value;
				ptr->value = temp;
			}
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
}