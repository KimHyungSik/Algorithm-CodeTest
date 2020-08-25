#include <iostream>
#include <string>

using namespace std;
int N[10000];

class Stack
{
public:
	int count = 0;
	void push(int num)
	{
		count++;
		N[count] = num;
	};
	int pop()
	{
		if (count == 0)
		{
			cout << -1 << endl;
			return -1;
		}
		else
		{
			cout << N[count] << endl;
			count--;
		}
	}
	void size()
	{
		cout << count << endl;
	}

	bool empty()
	{
		if (count == 0)
		{
			cout << 1 << endl;
			return 1;

		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	int top()
	{
		if (count == 0)
		{
			cout << -1 << endl;
			return -1;
		}
		else
		{
			cout << N[count] << endl;
		}
	}

};

int main(void)
{
	Stack stack;
	int num,odernum;
	string oder;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> oder;
		if (oder == "push")
		{
			cin >> odernum;
			stack.push(odernum);
		}
		if (oder == "pop")
		{
			stack.pop();
		}
		if (oder == "size")
		{
		    stack.size();
		}
		if (oder == "empty")
		{
			stack.empty();
		}
		if (oder == "top")
		{
			stack.top();
		}

	}
}
