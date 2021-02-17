// DP를 이용하여 빠르게 풀수 있는 문제
// 현재위치 이전에 작은 값이 을 찾은뒤
// 가장큰 부분 순열이 되게 계속 갱신 후
// 최댓값 출력

#include <iostream>

using namespace std;

int N;			 // 배열 길이 저장
int n[1001];	 // 배열 저장
int result[1001];// Dp데이터 저장

int main() {
	scanf("%d", &N);
	
	int max = 0;// 최댓값 확인용

	for (int i = 0; i < N; i++) { 
		int temp;
		scanf("%d", &temp); 
		n[i] = temp;
		result[i] = temp;
		max = max > temp ? max : temp;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			// 현재 위치 이전의 작은 값 확인
			if (n[j] < n[i]) {
				// DP값과 최댓값 갱신
				int t = result[j] + n[i];
				result[i] = result[i] > t ? result[i] : t;
				max = max > result[i] ? max : result[i];
			}
		}
	}
	printf("%d", max);
	return 0;
}