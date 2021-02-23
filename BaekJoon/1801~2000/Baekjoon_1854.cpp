// k��° �ִ� ��� ����
// ���ͽ�Ʈ�󿡼� �湮 Ƚ�� ������ �ذ�

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1010
#define INF 2000000000
using namespace std;

int n, m, k;
int visited[MAX];
// k��°�� �湮 �Ҽ� �ִ��� Ȯ�� 
// �ϱ����� 2���� �迭�� ����
int dp[MAX][MAX];
vector<pair<int, int>>v[MAX];

void dijkstra() {
	priority_queue<pair<int, int>>q;
	q.push(make_pair(0, 1));

	while (!q.empty()) {
		int cur = q.top().second;
		int weight = -q.top().first;

		q.pop();

		// k��° �湮������ �н�
		if (visited[cur] == k)continue;
		dp[visited[cur]++][cur] = weight;

		for (int i = 0; i < v[cur].size(); i++) {
			int t_cur = v[cur][i].first;
			int t_weight = weight + v[cur][i].second;
			q.push(make_pair(-t_weight, t_cur));
		}
	}
}

int main() {
	
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		int start, end, weight;
		scanf("%d %d %d", &start, &end, &weight);
		v[start].push_back(make_pair(end, weight));
	}

	// ���ͽ�Ʈ�� Ž���� ���� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INF;
		}
	}

	dijkstra();

	for (int i = 1; i <= n; i++) { 
		// �湮 �ߴ��� ���� �ߴ��� Ȯ��
		if (dp[k - 1][i] == INF) 
			printf("-1\n");
		else
			printf("%d\n", dp[k - 1][i]);
	}

	return 0;
}