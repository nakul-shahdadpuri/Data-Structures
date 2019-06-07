#include <iostream>
using namespace std;
typedef struct node{
	int data;
	node *right;
	node *left;
	int height;
}node;
int max(int a,int b);
int height(node *a)
{
	if(a == NULL)
		return 0;
	else 
		return a->height;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
node* newnode(int key)
{
	node *a = new node;
	a->data = key;
	a->left = NULL;
	a->right = NULL;
	a->height = 1;
	return a;
}
node* rightrotate(node *y)
{
	node *x = y->left;
	node *t = x->right;
	x->right = y;
	y->left = t;

	y->height = max(height(y->left),height(y->right))+ 1;
	x->height = max(height(x->left),height(x->right))+ 1;
	return x;
}
node* leftrotate(node *x)
{
	node *y = x->right;
	node *t = y->left;
	y->left = x;
	x->right = t;
	x->height = max(height(x->left),height(x->right))+1;
	y->height = max(height(y->left),height(y->right))+1;
}
int getbalance(node *a)
{
	if(a==NULL)
		return 0;
	return height(a->left) - height(a->right);
}
node* insert(node *node,int data)
{
	if(node == NULL)
		return newnode(data);
	if(data < node->data)
		node->left =  insert(node->left,data);
	else if (data > node->data)
		node ->right = insert(node->right,data);
	else
		return node;
	node ->height = 1 + max(height(node->left),height(node->right));
	int balance = getbalance(node);
	if(balance > 1 && data < node->left->data)
		return rightrotate(node);
	if(balance < -1 && data > node->right->data)
		return leftrotate(node);
	if(balance > 1 && data > node->left->data)
	{
		node->left = leftrotate(node->left);
		return rightrotate(node);
	}
	if(balance < -1 && data < node->right->data)
	{
		node ->right = rightrotate(node->right);
		return leftrotate(node);
	}	
	return node;
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	node *root = NULL;
	while(1)
	{
		cout << "enter 1 to insert 2 to traverse"<< endl;
		int a;
		cin >> a;
		if(a == 1)
		{
			cout << "enter the element you want to insert -" << endl;
			int g;
			cin >> g;
			root = insert(root,g);
		}
		else
		{
			preorder(root);
			cout << endl;
		}
	}
}