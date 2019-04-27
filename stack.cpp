#include <iostream>

using namespace std;
class stack
{
private:
	int a[10];
	int top = -1;
public:
	void push(int new_element)
	{
		top++;
		if(top!=10)
			a[top] = new_element;
		else
			cout << "stack overflow"; 
	}

	void pop()
	{
		top--;
	}

	void traverse()
	{
		int temp = 0;
		while(temp <= top)
		{
			cout << a[temp] << " " ;
			temp++;
		}
		cout << endl;
	}
	void enqueue(int new_element)
	{
		int b[top+1],i=0,temp=top;
		while(temp!=-1)
		{
			b[i] = a[temp];
			pop();
			i++;
			temp--;
		}
		i--;
		push(new_element);
		while(i!=-1)
		{
			push(b[i]);
			i--;
		}
	}
};
int main()
{
	stack a;
	a.push(98765);
	a.traverse();
	a.push(12345);
	a.traverse();
	a.pop();
	a.traverse();
}