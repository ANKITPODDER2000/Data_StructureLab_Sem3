#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tree{
	int value;
	struct tree *left,*right;
}BT;

//Prototype
void insert(BT **,int );
BT* create(int );
void preOrder(BT *);
void postOrder(BT *);
void inOrder(BT *);

BT *head=NULL;

int main()
{
	system("cls");
	int op,val;
	while(1)
	{
		printf("\nEnter 1->Insert\nEnter 2->PreOrder\nEnter 3->InOrder\nEnter 4->PostOrder\nEnter 5->Exit\nEnter the option : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\nENter the value to insert in Binary tree : ");
				scanf("%d",&val);
				insert(&head,val);
				break;
			case 2:
				printf("\nPreOrder is : ");
				preOrder(head);
				break;
			case 3:
				printf("\nInOrder is : ");
				inOrder(head);
				break;
			case 4:
				printf("\nPostOrder is : ");
				postOrder(head);
				break;
			case 5:
				printf("\nEnd of Program.");
				exit(0);
			default:
				printf("\nWrong input,Try again.");
				break;
		}
		printf("\nEnter any key to continue : ");
		getch();
		system("cls");
	}
}
void insert(BT **ptr,int val)
{
	if(*ptr==NULL)
	{
		*ptr = create(val);
		return;
	}
	else if((*ptr)->value > val)
		insert(&((*ptr)->left),val);
	else
		insert(&((*ptr)->right),val);
}
BT* create(int val)
{
	BT *new_node = (BT *)malloc(sizeof(BT));
	new_node->value = val;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
void preOrder(BT *ptr)
{
	if(ptr){
		printf("%d ",ptr->value);
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}
void inOrder(BT *ptr)
{
	if(ptr){
		inOrder(ptr->left);
		printf("%d ",ptr->value);
		inOrder(ptr->right);
	}
	return;
}
void postOrder(BT *ptr)
{
	if(ptr){
		postOrder(ptr->left);
		postOrder(ptr->right);
		printf("%d ",ptr->value);
	}
	return;
}