#include <iostream>

using namespace std;

typedef struct node 
{
	int data;
	struct node *NEXT;
	struct node *PREV;
} node;

node *HEAD = NULL;
node *TAIL = NULL;

void insert_head(int new_element)
{
	if(HEAD == NULL && TAIL == NULL)
	{
		node *a;
		a = (node*)malloc(sizeof(node));
		a -> data = new_element;
		HEAD = a;
		TAIL = a;
		a -> NEXT = NULL;
		a -> PREV = NULL;
		return ;
	}
	else
	{
		node *a;
		a = (node*)malloc(sizeof(node));
		a -> data = new_element;
		a -> PREV = NULL;
		HEAD -> PREV = a;
		a -> NEXT = HEAD;
		HEAD = a;
		return ;
	}
}
void insert_tail(int new_element)
{
	if(HEAD == NULL && TAIL == NULL)
	{
		insert_head(new_element);
		return ;
	}
	else
	{
		node *a;
		a = (node*) malloc(sizeof(node));
		a -> data = new_element;
		TAIL -> NEXT = a;
		a -> PREV = TAIL;
		TAIL = a;
	}

}
void insert_pos(int new_element , int pos)
{
	node *TEMP = HEAD,*ATEMP;
	int count = 0;
	while(count != pos -1 ) 
	{
		TEMP = TEMP -> NEXT;
		count++;
	}
	ATEMP = TEMP -> NEXT;
	node *a;
	a = (node*)malloc(sizeof(node));
	a -> data = new_element;
	a -> NEXT = ATEMP;
	ATEMP -> PREV = a;
	a -> PREV = TEMP;
	TEMP -> NEXT = a;
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
void back_traverse()
{
	node *TEMP = TAIL;
	while(TEMP != NULL)
	{
		cout << TEMP -> data;
		TEMP = TEMP -> PREV;
	}
}
int main()
{
}