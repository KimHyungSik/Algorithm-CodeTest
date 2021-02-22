// 2���� �迭���� ���� Ž�� ����
// �湮 ���ǿ� ������ ���� �� ���� 
// ���� �����ϴ� ���� �߰�

#include <iostream>
#define MAX 21

using namespace std;

int R, C;						// Y, X ũ��
int result = 1;				
char grid[MAX][MAX];
bool pos[MAX][MAX] = { 0 };		// ��ġ�� �湮 �ߴ��� Ȯ��
bool visited[27] = { 0 };		// ���� �湮 Ȯ��

void dfs(int x, int y, int move) {
	// �� ū ������ ���� ����
	result = result > move ? result : move;

	int tx[4] = { 1, -1, 0, 0 };
	int ty[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int tex = x + tx[i];
		int tey = y + ty[i];
		// ��ǥ�� ���� ���� �ִ��� Ȯ��
		// ���� �� ������ �ִ� �������� Ȯ��
		// �湮 ���� Ȯ��
		if (tex >= 0 && tey >= 0 && tex < C && tey < R && !visited[grid[tey][tex] - 'A'] && !pos[tey][tex]) {
			visited[grid[tey][tex] - 'A'] = true;
			pos[tey][tex] = true;
			// ��ǥ�� �̵� Ƚ�� �߰��� DFS
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

	// ù�� °(0,0)�� �����ϴ� ��ġ ó��
	pos[0][0] = true;
	visited[grid[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	printf("%d", result);
	return 0;
}
