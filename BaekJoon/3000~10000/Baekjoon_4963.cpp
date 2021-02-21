// ���� Ž���� �̿��ϴ� ����
// DFS������� �ذ�
#include <iostream>
#include <vector>
#define MAX 52

using namespace std;

bool graph[MAX][MAX];
int result;
int w, h;

// dfs��� ����
// x��ǥ, y��ǥ, �湮 ��
void visit(int x, int y, bool (*vi)[MAX]) {
	// ��� ���� ã��
	int tx[3] = { -1,0,1 };
	int ty[3] = { -1,0,1 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tex = x + tx[j];
			int tey = y + ty[i];
			if (tex >= 0 && tey >= 0 && tex < w && tey < h) {
				if (graph[tey][tex] && !vi[tey][tex]) {
					vi[tey][tex] = 1;
					visit(tex, tey, vi);
				}
			}
		}
	}
}

int main() {
	while(true){
		vector<pair<int, int>> v;
		result = 0;

		bool visited[MAX][MAX] = { 0 };

		scanf("%d %d", &w, &h);
		if (!w && !h) break;

		for (int j = 0; j < h; j++) {
			for(int k = 0; k < w; k++){
				scanf("%d", &graph[j][k]);
				if (graph[j][k]) {	// �� �̶�� ���Ϳ� �߰�
					v.push_back(make_pair(j, k));
				}
			}
		}

		// ���� �� ���� Ȯ��
		while (!v.empty()) {
			int y = v.back().first;
			int x = v.back().second;
			v.pop_back();
			if (graph[y][x] && !visited[y][x]) {
				visit(x, y, visited);
				result++;
			}
		}
		printf("%d\n", result);
	}

	return 0;
}