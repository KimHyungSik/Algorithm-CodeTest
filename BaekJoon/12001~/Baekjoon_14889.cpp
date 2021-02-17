// dfs ������� ������ ����� �� Ž��
// ���� �ΰ��� ������ ������ 
// 1������ �ִ��� ���� ���� ���� ������ ���

#include <iostream>
#include <vector>
#define MAX 21
#define INF 1000000000
using namespace std;

int n[MAX][MAX];		
int N;
int result = INF;		// ������ �������� �ʱ�ȭ
bool visited[MAX];

void sc() {
	vector<int> start;
	vector<int> link;
	int team1 = 0, team2 = 0;
	// �湮 ���η� ���� ������
	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			start.push_back(i);
		}
		else {
			link.push_back(i);
		}
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = i+1; j < N / 2; j++) {
			team1 += n[start[i]][start[j]] + n[start[j]][start[i]];
			team2 += n[link[i]][link[j]] + n[link[j]][link[i]];
		}
	}

	if (team1 > team2) {
		result = result < team1 - team2 ? result : team1 - team2;
	}
	else {
		result = result < team2 - team1 ? result : team2 - team1;
	}
	return;
}

void dfs(int cur, int x) {
	// ������ �ٱ��ϸ� ��Ʈ��ŷ
	if (x == N / 2) {
		sc();
		return;
	}
	//���� ���ϱ�
	for (int i = cur+1; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, x+1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &n[i][j]);
		}
	}

	visited[0] = true;
	dfs(0,1);

	printf("%d", result);
	return 0;
}
