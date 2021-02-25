// DP�� ���� �ذ�
// ���� �ڽ��� �� �Ǵ� �ٷ� ������ ������ �ִ밪 + �ڽ��� ������
// �� �ִ� �� Ȯ��

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
		if (i > 0) {// ���� ������ ���ϸ鼭 �ִ밪 ����
			dp[i] = MAX(grid[i], dp[i - 1] + grid[i]);
			result = MAX(result, dp[i]);
		}// ���� ���� ���ٸ� DP�� result �� �ʱ�ȭ
		else {
			dp[i] = grid[i];
			result = dp[i];
		}
	}

	cout << result << '\n';
	return 0;
}