// 100 * 100 크기의 도화지를 만든뒤 
// 새로운 색종이를 붙였을 때 겹치는지 확인

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
				// 색종이가 붙어있다면 패스
				if (grid[k][j])continue;
				// 색종이가 붙어 있지 않다면 붙이고 붙은 넓이 갱신
				grid[k][j] = true;
				result++;
			}
		}
	}
	cout << result << '\n';
	return 0;
}