// ������ ����� �������� ��� 
// ���� �� �κ� ���� ���� + ���� ��  �κ� ���� ����
// ���� �ι� �� �ڽ��� ����

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
		// ���� �� �κ� ���� ���� �˻�
		for (int j = 0; j < i; j++) {
			if (grid[i] > grid[j] && up[i] < up[j] + 1) {
				up[i] = up[j] + 1;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		// ���� ª�� �κ� ���� ���� �˻�
		for (int j = N - 1; j > i; j--) {
			if (grid[i] > grid[j] && down[i] < down[j] + 1) {
				down[i] = down[j] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		// �ִ� �� ã�Ƽ� ����
		result = MAX(result, up[i] + down[i] - 1);
	}

	cout << result << '\n';
	return 0;
}