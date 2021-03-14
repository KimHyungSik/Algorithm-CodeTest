// DFS를 이용하여 각각의 노드를 탐색
// 플로이드 와샬 알고리즘으로도 해결 가능
#include <iostream>
#include <cstring>
#define MAXN 101

int graph[MAXN][MAXN];
int n;
bool visited[MAXN];

using namespace std;

void dfs(int start, int pos) {
	for (int i = 1; i <= n; i++) {
		if (graph[start][i] && !visited[i]) {
			visited[i] = 1;
			graph[pos][i] = 1;
			dfs(i, pos);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)  {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}