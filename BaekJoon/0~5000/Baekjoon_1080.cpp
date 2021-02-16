// ���� ��ġ�� �� ���� �ٸ��ٸ� 
// ���� ������ �ٲ� ���鼭 ����

#include <iostream>

bool A[51][51];
bool B[51][51];

int N, M;

bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) return false;
		}
	}
	return true;
}

void swap(int x, int y) {
	// 3x3 ����
	// ���� ��ġ���� 2x2���� ����
	int tx[9] = { 0, 1, 2};
	int ty[9] = { 0, 1, 2};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[x + tx[i]][y + ty[j]] = !A[x + tx[i]][y + ty[j]];
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &A[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &B[i][j]);
		}
	}
	int result = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {		// ���� ��ġ�� �񱳴���� �ٸ��ٸ� ����
				result++;
				swap(i, j);
				if (check()) {				// ���� �ȴٸ� ��
					printf("%d", result);	// ���ٸ� ����Ƚ �� ��� �� ����
					return 0;
				}
			}
		}
	}
	// ���� 3x3���� ���� ���
	// ���Ƶ� �ΰ��� ����� ���� ��� '0'�� ��� �Ѵ�
	if (check()) {
		printf("%d", result);
	}
	else {
		printf("-1");
	}
	return 0;
}