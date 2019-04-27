#include <iostream>
#include <cmath>
using namespace std;
typedef struct node 
{	
	int data;
	node* left;
	node* right;
}node ;
node *root = NULL;
void insert(int key)
{
	node *a;
	a = new node;
	a -> data = key;
	a -> left = NULL;
	a -> right = NULL;
	if(root == NULL)
		root = a;
	else
	{
		node *parent ,*current = root;
		while(1)
		{
			parent = current;
			if(key < current -> data)
				current = current -> left;
			else if(key > current -> data)
				current = current -> right;
			if(current == NULL)
				break;
		}
		if(key > parent-> data)
			parent -> right = a;
		else
			parent -> left = a;
	}
}
node* smallest(node *boot)
{
	node *parent,*current = boot;
	if(boot == NULL)
		cout << "NOTHING TO DELETE";
	while(1)
	{
		parent = current;
		current = current -> left;
		if(current == NULL)
			break;
	}
	return parent;
}

node* largest(node *foot)
{
	node *btemp;
	node *temp = foot;
	while(1)
	{	
		btemp = temp;
		temp = temp -> right;
		if(temp == NULL)
			break;
	}
	return btemp; 
}
void deletion(int key)
{	
	if(root == NULL)
		cout << "NOTHING TO DELETE";
	else if(root -> right == NULL && root -> left == NULL && root != NULL && root->data == key)
	{
		free(root);
		root = NULL;
	}
	else 
	{
		node *parent,*current = root;
		while(1)
		{
			parent = current;
			if(key < current -> data)
				current = current -> left;
			else if(key > current -> data)
				current = current -> right;
			if(current->data == key)
				break;
		}
		if(current -> left == NULL && current -> right == NULL) //deleting leaf nodes
		{
			if(key > parent -> data)
			{
				node *a = parent -> right;
				delete a;
				parent -> right =  NULL;
			}
			else
			{
				node *a = parent -> left;
				delete a;
				parent -> left = NULL;
			}
		}
		else if(current -> left == NULL ||   current -> right == NULL) //deleting nodes with one child
		{	if(key > parent -> data)
			{
				if(current -> left == NULL)
				{
					parent -> right = current -> right;
					delete current;
				}
				else
				{
					parent -> right = current -> left;
					delete current; 
				}
			}
			else
			{
				if(current -> left == NULL)
				{
					parent -> left = current -> right;
					delete current;
				}
				else 
				{
					parent -> left = current -> left;
					delete current; 
				}	
			}
		}
		else if(current -> left != NULL && current -> right != NULL)
		{
			int temp;
			  node *a = smallest(current->right);
			  temp = a -> data;
			  deletion(a->data);
			  current -> data = temp;
		}
	}
}
void inorder(node *chroot)
{
	if(chroot!=NULL)
	{
		inorder(chroot -> left);
		cout << chroot -> data << " ";
		inorder(chroot -> right);
	}
}
void postorder(node *chroot)
{
	if(chroot!=NULL)
	{
		postorder(chroot -> left);
		postorder(chroot -> right);
		cout << chroot -> data << " ";

	}
}
void preorder(node *chroot)
{
	if(chroot!=NULL)
	{
		cout << chroot -> data << " ";
		preorder(chroot -> left);
		preorder(chroot -> right);
	}
}
int main()
{
	while(1)
	{
		int n;
		cout << "enter 1 to insert \nenter 2 to delete(except root node) \nenter 3 for inorder \nenter 4 for postorder \nenter 5 for preorder \nenter 6 to exit\n";
		cin >> n;
		if(n == 1)
		{
			int x;
			cout << "enter -";
			cin >> x;
			insert(x);
		}
		else if(n == 2)
		{
			int x;
			cout << "enter -";
			cin >> x;
			deletion(x);
		}
		else if(n == 3)
		{
			inorder(root);
			cout << endl;
		}
		else if(n == 4)
		{
			postorder(root);
			cout << endl;
		}
		else if(n == 5)
		{
			preorder(root);
			cout << endl;			
		}
		else if(n == 6)
		{
			exit(0);
		}
	}
}