//9. 성적이 반 평균보다 높은 사람의 학번 리스트를 출력
//1) 입력형식
//학번, 성적
//2) 출력형식
//성적이 반평균보다 높은 사람의 학번리스트
//3) 처리 조건
//처리할 자료의 개수는 30명 미만
//데이터의 끝을 검사하라.
//데이터의 끝 == = 999입력되면 끝
//반평균을 구한 후, 반평균보다 성적이 높은 사람의 학번을 출력
//4) 주의 사항
//배열의 필요성
//	: 개개인의 출력 기준이 반 평균보다 성적이 높은 사람의
//	학번이므로 우선적으로 반 평균을 먼저 구해야 함
//	반 평균을 구하는 과정에서 모든 데이터를 읽어서 배열에 기억해 두어야 함

#include <stdio.h>

int main() {
	int hakbun[29], sungjuk[29],i = 0,tot=0;
	for (; i < 29; i++) {
		scanf_s("%d %d", &hakbun[i], &sungjuk[i]);
		if (hakbun[i] == 999 || sungjuk[i] == 999) {
			break;
		}
		tot += sungjuk[i];
	}
	int avg = tot / i;
	printf("평균이상 학번:");
	for (int j = 0; j < i; j++) {
		if (sungjuk[j] > avg) {
			printf("%d, ", hakbun[j]);
		}
	}
	printf("\n");
}