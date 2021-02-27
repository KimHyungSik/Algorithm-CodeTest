// bfs�� ���� �������ġ�� �ľ� �ϱ⸸�ϸ�
// �����ϰ� Ǯ�� �ִ� ����

#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#define MAXN 21

using namespace std;

int grid[MAXN][MAXN];		// ����� ����
int visited[MAXN][MAXN];	// �湮���� Ȯ��
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


			// ������ �Ѿ�ų�
			// �Ʊ� ���� ũ�ų�
			// �ѹ� ���� ���� ����
			if (X < 0 || Y < 0 || X >= n || Y >= n)continue;
			if (grid[Y][X] > Ssize || visited[Y][X] != -1)continue;

			visited[Y][X] = visited[y_][x_] + 1;

			// ������ �ִ� ����Ⱑ �ڸ��� �����鼭
			if (grid[Y][X] < Ssize && grid[Y][X]) {
				// ������ ����
				if (dis > visited[Y][X]) {
					dis = visited[Y][X];
					target_x = X;
					target_y = Y;
				}
				// ���� �Ÿ��� ����Ⱑ �ִٸ�
				// ������ ������ ���� ���� ���� Ȯ��
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
		
		// ���� ����� ��ǥ �ʱ�ȭ
		target_x = -1;
		target_y = -1;

		// �湮���� �ʱ�ȭ
		memset(visited, -1, sizeof(visited));

		visited[y][x] = 0;

		bfs(x, y);
		
		// ������ ���� ����Ⱑ ���ٸ� ����
		if (target_x == -1 && target_y == -1)break;
		grid[target_y][target_x] = 0;

		// ���������� �Ÿ� ����
		result += visited[target_y][target_x];
		eat++;

		// ������ Ŀ���� �ܰ�
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
