// bfs로 다음 물고기위치를 파악 하기만하면
// 간단하게 풀수 있는 문제

#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#define MAXN 21

using namespace std;

int grid[MAXN][MAXN];		// 물고기 저장
int visited[MAXN][MAXN];	// 방문지점 확인
int n;
int target_x = -1, target_y = -1;
int Ssize = 2;

void bfs(int x, int y) {
	int dis = 2000000000;
	int tx[] = { 1,-1,0,0 };
	int ty[] = { 0,0,1,-1 };

	queue<pair<int, int>> q;

	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x_ = q.front().first;
		int y_ = q.front().second;
	
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = x_ + tx[i];
			int Y = y_ + ty[i];


			// 범위를 넘어가거나
			// 아기 상어보다 크거나
			// 한번 갔던 지역 제외
			if (X < 0 || Y < 0 || X >= n || Y >= n)continue;
			if (grid[Y][X] > Ssize || visited[Y][X] != -1)continue;

			visited[Y][X] = visited[y_][x_] + 1;

			// 먹을수 있는 물고기가 자리에 있으면서
			if (grid[Y][X] < Ssize && grid[Y][X]) {
				// 가까우면 갱신
				if (dis > visited[Y][X]) {
					dis = visited[Y][X];
					target_x = X;
					target_y = Y;
				}
				// 같은 거리에 물고기가 있다면
				// 문제의 조건의 따라 갱신 여부 확인
				else if (dis == visited[Y][X]) {
					if (target_y == Y) {
						if (target_x > X) {
							target_x = X;
							target_y = Y;
						}
					}else if (target_y > Y) {
						target_x = X;
						target_y = Y;
					}
				}
			}
			q.push(make_pair(X, Y));
		}

	}

}


int main() {
	int x, y;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == 9) {
				y = i;
				x = j;
			}
			
		}
	}
	int result = 0;
	int eat = 0;
	grid[y][x] = 0;
	while (true) {
		
		// 다음 물고기 좌표 초기화
		target_x = -1;
		target_y = -1;

		// 방문지점 초기화
		memset(visited, -1, sizeof(visited));

		visited[y][x] = 0;

		bfs(x, y);
		
		// 다음에 먹을 물고기가 없다면 종료
		if (target_x == -1 && target_y == -1)break;
		grid[target_y][target_x] = 0;

		// 물고기까지의 거리 갱신
		result += visited[target_y][target_x];
		eat++;

		// 몸집이 커지는 단계
		if (eat == Ssize) { 
			Ssize++;
			eat = 0;
		}
		x = target_x;
		y = target_y;
	}

	printf("%d",result);
	return 0;
}
