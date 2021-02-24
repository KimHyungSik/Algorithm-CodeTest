// 무난한 DP문제

#include <iostream>
#define MAX 1001

using namespace std;

int grid[MAX];
int result[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int re = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> grid[i];
		// 현재 입력 받은 값의 이전 값들 검색
		for (int j = 0; j < i; j++) {
			// 만약 이전에 더 큰 값이 있는 경우
			if (grid[j] > grid[i]) {
				// DP배열에서 더 긴 감소 하는 수열 로 갱신
				result[i] = result[i] > result[j] + 1 ? result[i] : result[j] + 1;
				re = re > result[i] ? re : result[i];
			}
		}
	}
	cout << re +1 << '\n';
	return 0;
}