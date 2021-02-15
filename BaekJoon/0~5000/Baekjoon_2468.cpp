// �ִ� ������ Ȯ�� �� ������ 0���� �ִ밭���� ����
// ������ dfs�� Ȯ���ϸ鼭 �ִ� ���� ����
// �ִ� 100 * 100 * 100 �ð� ���⵵

#include <iostream>
#include <cstring>
#define MAX 101

using namespace std;

int grid[MAX][MAX];
int N;
int max_h = 0, result = 1;	// �ִ� ���� ��� ��, ���� Ȯ��
bool visited[MAX][MAX];

// ���翡�� ���� ��� �湮 ó��
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
		// �湮��� �ʱ�ȭ
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < N; j++) {
			for (int t = 0; t < N; t++) {
				// �湮 ���� �ʾ����� ���� ������ ���� ���� ���� Ȯ��
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
