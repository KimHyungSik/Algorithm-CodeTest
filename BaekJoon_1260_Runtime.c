#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int to, from;
int J, G, start;
vector<int> vc[1000];
queue<int> qu;

class beckjoon
{
public:
	int DFScnt[1000] = { 0, };
	int BFScnt[1000] = { 0, };
	void DFS(int num)
	{
		DFScnt[num] = 1;
		cout << num;
		for (int i = 0; i < vc[num].size(); i++)
		{
			if (DFScnt[vc[num][i]] == 0)
			{
				return DFS(vc[num][i]);
			}
		}
	}
	void BFS(int num)
	{
		qu.push(num);
		while (qu.empty()==0)
		{
			BFScnt[num] = 1;
			for (int i = 0; i < vc[num].size(); i++)
			{
				if (BFScnt[vc[num][i]] == 0)
				{
					qu.push(vc[num][i]);
					BFScnt[vc[num][i]] = 1;
				}
			}
			if (BFScnt[qu.front()] == 1)
			{
				cout << qu.front();
				BFScnt[qu.front()] = 2;
				qu.pop();

			}
		}
	}
};

int main()
{
	beckjoon jb;
	cin >> J >> G >> start;

	for (int i = 0; i < G; i++)
	{
		cin >> from >> to;

		vc[from].push_back(to);
		vc[to].push_back(from);
	}
	jb.DFS(start);
	cout << endl;
	jb.BFS(start);


	return 0;
}
