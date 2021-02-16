// 현재 위치가 비교 대상과 다르다면 
// 지속 적으로 바꿔 가면서 진행

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
	// 3x3 변경
	// 현재 위치에서 2x2까지 변경
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
			if (A[i][j] != B[i][j]) {		// 현재 위치와 비교대상이 다르다면 갱신
				result++;
				swap(i, j);
				if (check()) {				// 갱신 된다면 비교
					printf("%d", result);	// 같다면 변경횟 수 출력 후 종료
					return 0;
				}
			}
		}
	}
	// 만약 3x3보다 작을 경우
	// 같아도 두개의 행렬이 같은 경우 '0'을 출력 한다
	if (check()) {
		printf("%d", result);
	}
	else {
		printf("-1");
	}
	return 0;
}