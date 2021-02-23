// k번째 최단 경로 문제
// 다익스트라에서 방문 횟수 증가로 해결

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1010
#define INF 2000000000
using namespace std;

int n, m, k;
int visited[MAX];
// k번째로 방문 할수 있는지 확인 
// 하기위해 2차원 배열로 생성
int dp[MAX][MAX];
vector<pair<int, int>>v[MAX];

void dijkstra() {
	priority_queue<pair<int, int>>q;
	q.push(make_pair(0, 1));

	while (!q.empty()) {
		int cur = q.top().second;
		int weight = -q.top().first;

		q.pop();

		// k번째 방문했으면 패스
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

	// 다익스트라 탐색을 위한 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INF;
		}
	}

	dijkstra();

	for (int i = 1; i <= n; i++) { 
		// 방문 했는지 실패 했는지 확인
		if (dp[k - 1][i] == INF) 
			printf("-1\n");
		else
			printf("%d\n", dp[k - 1][i]);
	}

	return 0;
}