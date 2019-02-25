#include <iostream>

using namespace std;

typedef struct node 
{
	int data;
	struct node *NEXT;
} node ;

node *HEAD = NULL;

void add_head(int new_element)
{
	node *a;
	a = (node*) malloc(sizeof(node));
	a -> data = new_element; 
	a -> NEXT = HEAD;
	HEAD = a;
}
void add_back(int new_element)
{
	if(HEAD!=NULL)
	{
		node *TEMP = HEAD;
		while(TEMP -> NEXT != NULL)
		{
			TEMP = TEMP -> NEXT;
		}
		node *a;
		a = (node*) malloc(sizeof(node));
		TEMP -> NEXT = a;
		a -> data =  new_element;
		a -> NEXT = NULL;
	}
	else
	{
		add_head(new_element);
	}
}
void add_pos(int new_element,int insert_position)
{
	node *TEMP = HEAD,*ATEMP;
	int count = 0;
	while(count != insert_position -1 ) 
	{
		TEMP = TEMP -> NEXT;
		count++;
	}
	ATEMP = TEMP -> NEXT;
	node * a;
	a = (node*)malloc(sizeof(node));
	a -> data = new_element;
	TEMP -> NEXT = a;
	a -> NEXT = ATEMP;
}
void delete_head()
{
	node *TEMP = HEAD;
	HEAD = HEAD -> NEXT;
	free(TEMP);
}
void delete_tail()
{
	node *TEMP = HEAD,*a;
	while(TEMP -> NEXT != NULL)
	{
		a = TEMP;
		TEMP = TEMP -> NEXT;
	}
	free(TEMP);
	a -> NEXT = NULL;
}
void traverse()
{
	node *TEMP = HEAD;
	while(TEMP != NULL)
	{
		cout << TEMP -> data;
		TEMP = TEMP -> NEXT;
	}
}
