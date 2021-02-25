// Union-Find 알고리즘 문제

#include <iostream>
#include <cstring>
#define MAXN 3001

using namespace std;

int base[MAXN][3];	// x좌표, y좌표, 거리
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

				// 두좌 표 간의 거리와 전파가 전달 되는지 확인
				if (pos <= r * r) {
					// 전달되는데 같은 그룹이 아닌경우 
					// 유니온 해주고 전체 그룹수 감소
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