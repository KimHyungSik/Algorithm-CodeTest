// Union-Find �˰��� ����

#include <iostream>
#include <cstring>
#define MAXN 3001

using namespace std;

int base[MAXN][3];	// x��ǥ, y��ǥ, �Ÿ�
int parents[MAXN];

int find(int x) {
	if (parents[x] == x)return x;
	else return parents[x] = find(parents[x]);
}

void mer(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)return;
	else parents[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		memset(base, 0, sizeof(base));
		memset(parents, 0, sizeof(parents));

		for (int i = 0; i < n; i++){
			cin >> base[i][0] >> base[i][1] >> base[i][2];
			parents[i] = i;
		}

		int result = n;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int x = base[i][0] - base[j][0];
				int y = base[i][1] - base[j][1];
				int r = base[i][2] + base[j][2];
				int pos = x * x + y * y;

				// ���� ǥ ���� �Ÿ��� ���İ� ���� �Ǵ��� Ȯ��
				if (pos <= r * r) {
					// ���޵Ǵµ� ���� �׷��� �ƴѰ�� 
					// ���Ͽ� ���ְ� ��ü �׷�� ����
					if (find(i) != find(j)) {
						mer(i, j);
						result--;
					}
				}

			}
		}
		cout << result << '\n';
	}
	return 0;
}