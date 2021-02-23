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
	// ��� ��Ʈ�� 1 �̶�� ��� �湮 �Ϸ�
	if (visited == (1 << n) - 1) {
		return grid[here][0] ? grid[here][0] : INF;
	}

	// ���� �湮�� �Ÿ� ��
	int ret = dp[here][visited];

	// ������ �湮�� ���ִٸ� ��ȯ
	if (ret != -1)return ret;

	ret = INF;

	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;	// �湮 �ߴ� ��ġ��� �н�
		if (grid[here][i] == 0) continue;	// �湮 �Ҽ� ���� �� �Ǵ� �ڱ� �ڽ��ϰ�� �н�
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