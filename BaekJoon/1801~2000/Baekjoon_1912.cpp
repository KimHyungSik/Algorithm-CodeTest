// DP로 문제 해결
// 현재 자신의 값 또는 바로 이전값 까지의 최대값 + 자신의 값으로
// 총 최대 값 확인

#include <iostream>
#define MAXN 100001 

using namespace std;

int grid[MAXN];
int dp[MAXN];
int n;

int MAX(int x, int y) {
	return x > y ? x : y;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++) { 
		cin >> grid[i]; 
		if (i > 0) {// 이전 값들을 비교하면서 최대값 갱신
			dp[i] = MAX(grid[i], dp[i - 1] + grid[i]);
			result = MAX(result, dp[i]);
		}// 이전 값이 없다면 DP와 result 값 초기화
		else {
			dp[i] = grid[i];
			result = dp[i];
		}
	}

	cout << result << '\n';
	return 0;
}