#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct equ{
	int co,ex;
	struct equ *next;
}E;
void create(E *);
void display(E *);
void insert(E **,int ,int );
void s(E *,E *);

E *sum = NULL;

int main()
{
	E *equ1 = (E *)malloc(sizeof(E));
	E *equ2 = (E *)malloc(sizeof(E));
	printf("\nCreate 1st Equation : ");
	create(equ1);
	printf("\nCreate 2nd Equation : ");
	create(equ2);
	printf("\n1st equ is :");
	display(equ1);
	printf("\n2nd Equ is :");
	display(equ2);
	s(equ1,equ2);
	printf("\nSum is : ");
	display(sum);
	return 0;
}
void create(E *ptr)
{
	char ch;
	printf("\nEnter co-eff & exp : ");
	scanf("%d%d",&ptr->co,&ptr->ex);
	ptr->next = NULL;
	printf("\nAre you want to insert a new node : ");
	scanf(" %c",&ch);
	if(ch=='Y' || ch=='y')
	{
		ptr->next = (E *)malloc(sizeof(E));
		ptr = ptr->next;
		create(ptr);
	}
}
void display(E *ptr)
{
	while(ptr)
	{
		if(ptr->next)
			printf(" (%d ^ %d) +",ptr->co,ptr->ex);
		else
			printf(" (%d ^ %d)",ptr->co,ptr->ex);
		ptr = ptr->next;
	}
}
void s(E *ptr1,E *ptr2)
{
	while(ptr1 && ptr2)
	{
		if(ptr1->ex > ptr2->ex)
		{
			insert(&sum,ptr1->co,ptr1->ex);
			ptr1 = ptr1->next;
		}
		else if(ptr2->ex > ptr1->ex)
		{
			insert(&sum,ptr2->co,ptr2->ex);
			ptr2 = ptr2->next;
		}
		else{
			insert(&sum,ptr2->co+ptr1->co,ptr2->ex);
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}
	if(!ptr1)
	{
		while(ptr2)
		{
			insert(&sum,ptr2->co,ptr2->ex);
			ptr2 = ptr2->next;
		}
	}
	else if(!ptr2)
	{
		while(ptr1)
		{
			insert(&sum,ptr1->co,ptr1->ex);
			ptr1 = ptr1->next;
		}
	}
}
void insert(E **ptr,int co,int ex)
{
	E *loc = *ptr;
	E *new_node = (E *)malloc(sizeof(E));
	new_node->co = co;
	new_node->ex = ex;
	new_node->next = NULL;
	if(*ptr==NULL)
	{
		*ptr = new_node;
		return;
	}
	while(loc->next)
		loc = loc->next;
	loc->next = new_node;
}