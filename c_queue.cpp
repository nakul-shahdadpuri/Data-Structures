#include <iostream>

using namespace std;

int a[10];
int front = -1;
int rear = -1;
int noe=0;
void enqueue(int new_element)
{
	if(noe==10)
	{
		cout << "overflow" << endl;
		exit(1);
	}
	if(rear == -1 && front == -1)
	{
		front = (front+1)%10;
		rear = (rear+1)%10;
		a[rear] = new_element;
		noe++;
		return;
	}
	else
	{
		rear=(rear+1)%10;
		a[rear] = new_element;
		noe++;
		return;
	}
}
void dequeue()
{
	if(front==rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front+1)%10;
		noe--;
	}
}
void show()
{
	int temp = front;
	if(front == rear && front == -1)
	{
		cout << "empty" << endl;
	}
	else
	{
	while(temp != rear)
	{
		cout << a[temp];
		temp = (temp+1)%10;
	}
	cout << a[temp];
	cout << endl;
	return;
	}
}
int main()
{
}
