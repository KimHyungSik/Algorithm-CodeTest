// 모든 연산 결과를 확인해야하는 완전 탐색문제
// DFS 연산자를 하나 씩 골라 모든 경우의 수의 결과 값을 확인
// 최대값 최솟값을 갱신

#include <iostream>
#include <queue>
// 문제에서 최대 10억 최소 -10억 이기때문에 
// 검사용 상수값 정의
#define MAX 1000000010
#define MIN -1000000010

using namespace std;

int N;
int n[12];
int op[4];
int result_max = MIN;
int result_min = MAX;

void dfs(int count, int num) {
	// 모든 수를 사용 했으면 값 갱신
	if (count == N) {
		result_max = result_max < num ? num : result_max;
		result_min = result_min > num ? num : result_min;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			int temp;
			// 연산자를 사용 했다고 연산자 개수 감소
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
				// 이전값 음수 확인
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