// 100 * 100 ũ���� ��ȭ���� ����� 
// ���ο� �����̸� �ٿ��� �� ��ġ���� Ȯ��

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
bool grid[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int result = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				// �����̰� �پ��ִٸ� �н�
				if (grid[k][j])continue;
				// �����̰� �پ� ���� �ʴٸ� ���̰� ���� ���� ����
				grid[k][j] = true;
				result++;
			}
		}
	}
	cout << result << '\n';
	return 0;
}