// 2차원 배열에서 완전 탐색 문제
// 방문 조건에 이전에 밞은 적 없는 
// 문자 여야하는 조건 추가

#include <iostream>
#define MAX 21

using namespace std;

int R, C;						// Y, X 크기
int result = 1;				
char grid[MAX][MAX];
bool pos[MAX][MAX] = { 0 };		// 위치에 방문 했는지 확인
bool visited[27] = { 0 };		// 문자 방문 확인

void dfs(int x, int y, int move) {
	// 더 큰 값으로 정답 갱신
	result = result > move ? result : move;

	int tx[4] = { 1, -1, 0, 0 };
	int ty[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int tex = x + tx[i];
		int tey = y + ty[i];
		// 좌표가 지도 내에 있는지 확인
		// 이전 에 밞은적 있는 문자인지 확인
		// 방문 여부 확인
		if (tex >= 0 && tey >= 0 && tex < C && tey < R && !visited[grid[tey][tex] - 'A'] && !pos[tey][tex]) {
			visited[grid[tey][tex] - 'A'] = true;
			pos[tey][tex] = true;
			// 좌표와 이동 횟수 추가로 DFS
			dfs(tex, tey, move + 1);
			pos[tey][tex] = false;
			visited[grid[tey][tex] - 'A'] = false;
		}
	}

}

int main() {
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
		}
	}

	// 첫번 째(0,0)로 시작하는 위치 처리
	pos[0][0] = true;
	visited[grid[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	printf("%d", result);
	return 0;
}
