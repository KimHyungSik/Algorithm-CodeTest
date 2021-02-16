// ��� ���� ����� Ȯ���ؾ��ϴ� ���� Ž������
// DFS �����ڸ� �ϳ� �� ��� ��� ����� ���� ��� ���� Ȯ��
// �ִ밪 �ּڰ��� ����

#include <iostream>
#include <queue>
// �������� �ִ� 10�� �ּ� -10�� �̱⶧���� 
// �˻�� ����� ����
#define MAX 1000000010
#define MIN -1000000010

using namespace std;

int N;
int n[12];
int op[4];
int result_max = MIN;
int result_min = MAX;

void dfs(int count, int num) {
	// ��� ���� ��� ������ �� ����
	if (count == N) {
		result_max = result_max < num ? num : result_max;
		result_min = result_min > num ? num : result_min;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			int temp;
			// �����ڸ� ��� �ߴٰ� ������ ���� ����
			op[i]--;
			switch (i) {
			case 0:
				temp = num + n[count];
				break;
			case 1:
				temp = num - n[count];
				break;
			case 2:
				temp = num * n[count];
				break;
			case 3:
				// ������ ���� Ȯ��
				if (num < 0) {
					temp = -num / n[count];
					temp = -temp;
				}
				else {
					temp = num / n[count];
				}
				break;
			}
			dfs(count + 1, temp);
			op[i]++;
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &n[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}
	dfs(1, n[0]);

	printf("%d\n%d", result_max, result_min);
	return 0;
}