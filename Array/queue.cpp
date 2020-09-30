#include <iostream>

using namespace std;
class queue
{
private:
	int front = -1;
	int rear = -1;
	int a[10];
public:
	void enqueue(int new_element)
	{
		if(front == -1 && rear == -1)
		{
			front++;
			rear++;
			a[rear] = new_element;
			return;
		}
		if(rear == 10 - front)
		{
			cout << "Queue overflow";
			return ;
		}
		else
		{
			rear++;
			a[rear] = new_element;
			return; 
		}
	}
	void dequeue()
	{
		front++;
	}
	void show()
	{
		int temp = front;
		while(temp <= rear)
		{
			cout << a[temp];
			temp++;
		}
		cout << endl;
	}
};