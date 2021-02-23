// �ּ� �Ÿ� �˻� ����
// ���ͽ�Ʈ��� �ذ�

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int n, m, x;
int grid[MAX][MAX];
vector<pair<int, int>>v[1001];

// ���ͽ�Ʈ�� �˰���
void DI(int start) {
	priority_queue<pair<int, int>>q;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		int cur = q.top().second;
		int price = -q.top().first;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int t_cur = v[cur][i].first;
			int t_price = price + v[cur][i].second;
			// ������ �˻��� ���� ���� �δ�, �������� ���� ���, ���� ��湮 ����
			if ((grid[start][t_cur] > t_price || grid[start][t_cur] == -1) && start != t_cur) {
				q.push(make_pair(-t_price, t_cur));
				grid[start][t_cur] = t_price;
			}
		}

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		v[start].push_back(make_pair(end, weight));
	}

	// ���� ���� �������� -1�� ����
	memset(grid, -1, sizeof(grid));

	// ��� �������� ���ͽ�Ʈ�� ����
	for (int i = 1; i <= n; i++) {
		DI(i);
	}

	int result = 0;
	// �պ� �Ÿ� ��� �� ���� ����
	for (int i = 1; i <= n; i++) {
		result = result > grid[i][x] + grid[x][i] ? result : grid[i][x] + grid[x][i];
	}
	cout << result << '\n';
	return 0;
}