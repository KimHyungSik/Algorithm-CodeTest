// DP�� �̿��Ͽ� ������ Ǯ�� �ִ� ����
// ������ġ ������ ���� ���� �� ã����
// ����ū �κ� ������ �ǰ� ��� ���� ��
// �ִ� ���

#include <iostream>

using namespace std;

int N;			 // �迭 ���� ����
int n[1001];	 // �迭 ����
int result[1001];// Dp������ ����

int main() {
	scanf("%d", &N);
	
	int max = 0;// �ִ� Ȯ�ο�

	for (int i = 0; i < N; i++) { 
		int temp;
		scanf("%d", &temp); 
		n[i] = temp;
		result[i] = temp;
		max = max > temp ? max : temp;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			// ���� ��ġ ������ ���� �� Ȯ��
			if (n[j] < n[i]) {
				// DP���� �ִ� ����
				int t = result[j] + n[i];
				result[i] = result[i] > t ? result[i] : t;
				max = max > result[i] ? max : result[i];
			}
		}
	}
	printf("%d", max);
	return 0;
}