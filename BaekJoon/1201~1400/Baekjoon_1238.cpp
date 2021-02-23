// 최소 거리 검색 문제
// 다익스트라로 해결

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int n, m, x;
int grid[MAX][MAX];
vector<pair<int, int>>v[1001];

// 다익스트라 알고리즘
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
			// 이전에 검색한 가격 보다 싸다, 갱신한적 없는 경우, 본인 재방문 금지
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

	// 최초 갱신 이전값을 -1로 설정
	memset(grid, -1, sizeof(grid));

	// 모든 정점에서 다익스트라 진행
	for (int i = 1; i <= n; i++) {
		DI(i);
	}

	int result = 0;
	// 왕복 거리 계산 후 정답 갱신
	for (int i = 1; i <= n; i++) {
		result = result > grid[i][x] + grid[x][i] ? result : grid[i][x] + grid[x][i];
	}
	cout << result << '\n';
	return 0;
}