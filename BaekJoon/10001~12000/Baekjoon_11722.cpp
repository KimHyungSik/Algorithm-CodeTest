// ������ DP����

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
		// ���� �Է� ���� ���� ���� ���� �˻�
		for (int j = 0; j < i; j++) {
			// ���� ������ �� ū ���� �ִ� ���
			if (grid[j] > grid[i]) {
				// DP�迭���� �� �� ���� �ϴ� ���� �� ����
				result[i] = result[i] > result[j] + 1 ? result[i] : result[j] + 1;
				re = re > result[i] ? re : result[i];
			}
		}
	}
	cout << re +1 << '\n';
	return 0;
}