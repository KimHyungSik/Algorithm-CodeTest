//8. 학생들의 성적 S[20]개을 입력받아서
//최고 성적과 최저 성적에 해당하는 학생이 몇명인지 출력
#include <stdio.h>

int main() {
	int A_arr[10], MAX_cnt = 0, MIN_cnt = 0;
	int* max = NULL, * min = NULL;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &A_arr[i]);
		if (max == NULL) {
			max = &A_arr[i];
			min = &A_arr[i];
		}
		else {
			if (*max < A_arr[i]) {
				max = &A_arr[i];
			}
			if (*min > A_arr[i]) {
				min = &A_arr[i];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (*max == A_arr[i]) {
			MAX_cnt++;
		}
		if (*min == A_arr[i]) {
			MIN_cnt++;
		}
	}
	printf("최고점 학생 수 == %d, 최저점 학생 수 == %d\n", MAX_cnt, MIN_cnt);
}