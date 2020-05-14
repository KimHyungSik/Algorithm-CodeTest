#include <iostream>

using namespace std;

class fabonacci
{
public:
	int ocnt=0;
	int zcnt=0;
	int fabo(int num)
	{
		if (num == 1)
		{
			ocnt++;
			return 1;
		}
		else if (num == 0)
		{
			zcnt++;
			return 0;
		}
		else
		{
			return fabo(num - 1) + fabo(num - 2);
		}
	}
};
int main()
{
	int num;
	int cnt;
	cin>>cnt;
	fabonacci baekjoon;
	for (int i = 0; i < cnt; i++)
	{
		cin >> num;
		baekjoon.zcnt = 0;
		baekjoon.ocnt = 0;
		baekjoon.pabo(num);
        cout << baekjoon.zcnt << " << baekjoon.ocnt << endl;
	}
	return 0;
}
