// ��Ʈ��ŷ ����
// ��Ʈ ����ũ�� Ȱ�� �Ͽ� ��Ʈ��ŷ ���� Ȯ��
// DFS�� ���� �ذ�

#include <iostream>
#include <cstring>
#define MAX 16
using namespace std;

int n;
int grid[MAX][5];
int target[4];
int result = -1;
int ret_pos;
bool visit[1 << MAX];

// ���� �湮�� ��, ���� ���� ����, ���� ������
void DFS(int visited, int price,int ret[5]) {
	// ��Ʈ��ŷ ����
	// �ѹ� ����غ� ������ ��� ����
	if (visit[visited])return;
	
	// ������ ���ǿ� �´� ��� ���� ����
	if (target[0] <= ret[0] && target[1] <= ret[1] && target[2] <= ret[2] && target[3] <= ret[3]) {
		// ó�� �����ų� ���� ������ �Ѱ�� ����
		if (result == -1 || result > price) {
			result = price; 
			ret_pos = visited;
		}
		// ���� ���� �湮 ó��
		visit[visited] = true;
		return;
	}

	// ���� ���� �湮 ó��
	visit[visited] = true;

	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;
		int temp_ret[5];
		for (int j = 0; j < 4; j++) {
			temp_ret[j] = ret[j] + grid[i][j];
		}
		DFS((visited | (1 << i)), price + grid[i][4], temp_ret);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < 4; i++)cin >> target[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		DFS((1 << i),grid[i][4] ,grid[i]);
	}

	cout << result << '\n';
	int num = 1;
	
	// ����� ��Ʈ ��� ���
	while (ret_pos > 0) {
		if (ret_pos & 1) cout << num << ' ';
		num++;
		ret_pos >>= 1;
	}

	return 0;
}