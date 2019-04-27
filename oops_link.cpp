#include <iostream>

using namespace std;

class link
{
	private:
	typedef struct node
	{
		int data;
		node *NEXT; 
	} node;
	node *HEAD = NULL;
	public:
	void insert_head(int new_element)
	{
		node *a;
		a = (node*)malloc(sizeof(node));
		a -> NEXT = HEAD;
		HEAD = a;
		a -> data = new_element;
	}
	void insert_end(int new_element)
	{
		node *a,*TEMP=HEAD;;
		a = (node*)malloc(sizeof(node));
		while(TEMP->NEXT!= NULL)
		{
			TEMP = TEMP -> NEXT;
		}
		a -> data = new_element;
		TEMP -> NEXT = a;
		a -> NEXT = NULL;
	}

	void insert_pos(int new_element,int pos)
	{
		int count = 0;
		node *a,*TEMP = HEAD,*ATEMP;
		while(count != pos -1)
		{
			TEMP = TEMP -> NEXT;
			count++;
		}
		ATEMP = TEMP -> NEXT;
		a = (node*)malloc(sizeof(node));
		TEMP -> NEXT = a;
		a -> data = new_element;
		a -> NEXT = ATEMP; 
	}

	void traverse()
	{
		node *TEMP = HEAD;
		while(TEMP!=NULL)
		{
			cout << TEMP->data << " ";
			TEMP = TEMP -> NEXT;
		}
	}
	void delete_head()
	{
		node *TEMP = HEAD;
		HEAD = HEAD -> NEXT;
		free(TEMP);	
	}
	void delete_tail()
	{
		node *TEMP = HEAD;
		node *BTEMP ;
		while(TEMP -> NEXT != NULL)
		{
			BTEMP = TEMP;
			TEMP = TEMP -> NEXT;
		}
		free(TEMP);
		BTEMP -> NEXT = NULL;
	}
	void delete_pos(int pos)
	{
		node *TEMP = HEAD,*ATEMP,*BTEMP;
		int count = 0; 
		while(count != pos - 1)
		{
			BTEMP = TEMP;
			TEMP = TEMP -> NEXT;
			count++;				
		}
		ATEMP = TEMP -> NEXT;
		free(TEMP);
		BTEMP -> NEXT = ATEMP;
	}
};
int main()
{
	link a;
	a.insert_head(456);
	a.insert_end(987);
	a.insert_pos(1234,1);
	a.traverse();
}