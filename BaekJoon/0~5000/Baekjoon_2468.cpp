// 최대 강수량 확인 후 강수량 0부터 최대강수량 까지
// 영역을 dfs로 확인하면서 최대 영역 갱신
// 최대 100 * 100 * 100 시간 복잡도

#include <iostream>
#include <cstring>
#define MAX 101

using namespace std;

int grid[MAX][MAX];
int N;
int max_h = 0, result = 1;	// 최대 높이 계산 용, 정답 확인
bool visited[MAX][MAX];

// 현재에서 영역 모두 방문 처리
void dfs(int h, int x, int y) {
	visited[x][y] = true;
	int px[4] = { 1, -1, 0, 0 };
	int py[4] = { 0, 0, 1, -1 };

	if (grid[x][y] > h) {
		for (int i = 0; i < 4; i++) {
			int tx = x + px[i];
			int ty = y + py[i];
			if (tx >= 0 && tx < N && ty >= 0 && ty < N && !visited[tx][ty]) {
				dfs(h, tx, ty);
			}
		}
	}
}

int main() {
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &grid[i][j]);
			max_h = max_h > grid[i][j] ? max_h : grid[i][j];
		}
	}

	for (int i = 0; i < max_h; i++) {
		int temp = 0;
		// 방문기록 초기화
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < N; j++) {
			for (int t = 0; t < N; t++) {
				// 방문 하지 않았으며 현재 강수량 보다 높은 지대 확인
				if (!visited[j][t] && grid[j][t] > i) {
					temp++;
					dfs(i, j, t);
				}
			}
		}
		result = result > temp ? result : temp;
	}

	printf("%d", result);

	return 0;
}
