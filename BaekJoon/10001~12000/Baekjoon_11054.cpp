// 문제가 어려워 보이지만 사실 
// 가장 긴 부분 증가 수열 + 가장 긴  부분 감소 수열
// 에서 두번 들어간 자신을 뺀값

#include <iostream>
#define MAXN 1001

using namespace std;

int MAX(int x, int y) {
	return x > y ? x : y;
}

int N;
int grid[MAXN];
int up[MAXN];
int down[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> grid[i];
		up[i] = 1;
		down[i] = 1;
		// 가장 긴 부분 증가 수열 검색
		for (int j = 0; j < i; j++) {
			if (grid[i] > grid[j] && up[i] < up[j] + 1) {
				up[i] = up[j] + 1;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		// 가장 짧은 부분 감소 수열 검색
		for (int j = N - 1; j > i; j--) {
			if (grid[i] > grid[j] && down[i] < down[j] + 1) {
				down[i] = down[j] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		// 최대 값 찾아서 갱신
		result = MAX(result, up[i] + down[i] - 1);
	}

	cout << result << '\n';
	return 0;
}