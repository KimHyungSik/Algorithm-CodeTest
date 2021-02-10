#include <iostream>
#include <queue>
#define INF 1000000000

using namespace std;

bool map[101][101];   // ����
int map_p[101][101];  // ����
int N, M;

void bfs() {
  // ���� ����
	int arr_x[4] = { 1, -1, 0, 0 };
	int arr_y[4] = { 0, 0, 1, -1 };
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int temp_x = x + arr_x[i];
			int temp_y = y + arr_y[i];
      // map ũ�� Ȯ��
			if (temp_x >= 0 && temp_x < M && temp_y >= 0 && temp_y < N) {
        // ���� ��ġ�� �̹� ��ġ���� ���� ����� �� ���� 
        // ������ ���ٸ� ����
				if (map_p[temp_x][temp_y] > map_p[x][y] + map[temp_x][temp_y]) {
					map_p[temp_x][temp_y] = map_p[x][y] + map[temp_x][temp_y];
					q.push(make_pair(temp_x, temp_y));
				}
			}
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++){
      int temp;
      scanf("%1d", &temp);
      map[i][j] = temp;
      map_p[i][j] = INF;
    }
	}

	map_p[0][0] = 0;
	
	bfs();

	cout<<map_p[M - 1][N - 1];

	return 0;
}