#include <iostream>
#include <string>

using namespace std;

int N[10000];

class queue
{
public:
	int count = 0;
	void push(int X)
	{
		count++;
		N[count] = X;
	}
	int pop()
	{
		if(count == 0)
		{
			cout << -1 << endl;
			return -1;
		}
		else
		{
			cout << N[1] << endl;
			count--;
			for (int i = 1; i <= count ; i++)
			{
				
				N[i] = N[i + 1];
			}
		}
	}
	int size()
	{
		cout << count << endl;
		return 0;
	}
	int empty()
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
	int front()
	{
		if (count == 0)
		{
			cout << -1<< endl;
			return -1;
		}
		else
		{
			cout << N[1] << endl;
			return 0;
		}

	}
	int back()
	{
		if (count == 0)
		{
			cout << -1 << endl;
			return -1;
		}
		else
		{
			cout << N[count] << endl;
			return 0;
		}
	}
};

int main(void)
{
	int num,ordernum;
	queue Queue;
	string order;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> ordernum;
			Queue.push(ordernum);

		}
		if (order == "pop")
		{
			Queue.pop();
		}
		if (order == "size")
		{
			Queue.size();
		}
		if (order == "empty")
		{
			Queue.empty();
		}
		if (order == "front")
		{
			Queue.front();
		}
		if (order == "back")
		{
			Queue.back();
		}

	}
	return 0;
}

