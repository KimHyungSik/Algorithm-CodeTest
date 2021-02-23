#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 16

const int INF = 2000000000;

using namespace std;

int n;
int dp[MAX][1 << MAX];
int grid[MAX][MAX];

int tsp(int here, int visited) {
	// 모든 비트가 1 이라면 모두 방문 완료
	if (visited == (1 << n) - 1) {
		return grid[here][0] ? grid[here][0] : INF;
	}

	// 현재 방문한 거리 합
	int ret = dp[here][visited];

	// 이전에 방문한 적있다면 반환
	if (ret != -1)return ret;

	ret = INF;

	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;	// 방문 했던 위치라면 패스
		if (grid[here][i] == 0) continue;	// 방문 할수 없는 곳 또는 자기 자신일경우 패스
		ret = min(ret, tsp(i, visited | (1 << i)) + grid[here][i]);
	}
	return dp[here][visited] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << '\n';
	return 0;

}