#include <iostream>
#include <string>

using namespace std;
int N[10000];

class Deck
{
public:
	int count = 0;
	void push_front(int X)
	{
		count++;
		N[0] = X;

		for (int i = count; i > 0; i--)
		{
			N[i] = N[i - 1];
		}
	}
	void push_back(int X)
	{
		count++;
		N[count] = X;
	}
	void pop_front()
	{
		if (count == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << N[1] << endl;
			count--;
			for (int i = 1; i <= count; i++)
			{
				N[i] = N[i + 1];
			}
		}
	}
	void pop_back()
	{
		if (count == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << N[count] << endl;
			count--;
		}
	}
	void empty()
	{
		if (count == 0)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	void size()
	{
		cout << count << endl;
	}
	void front()
	{
		if (count == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << N[1] << endl;
		}
	}
	void back()
	{
		if (count == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << N[count] << endl;
		}
	}
};

int main(void)
{
	Deck deck;
	int num,ordernum;
	string order;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> order;
		if (order == "push_front")
		{
			cin >> ordernum;
			deck.push_front(ordernum);
		}
		if (order == "push_back")
		{
			cin >> ordernum;
			deck.push_back(ordernum);

		}
		if (order == "pop_front")
		{
			deck.pop_front();
			
		}
		if (order == "pop_back")
		{
			deck.pop_back();
		}
		if (order == "size")
		{
			deck.size();
		}
		if (order == "empty")
		{
			deck.empty();
		}
		if (order == "front")
		{
			deck.front();
		}
		if (order == "back")
		{
			deck.back();
		}

	}
	return 0;

}