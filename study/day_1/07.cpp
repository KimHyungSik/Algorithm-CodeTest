//7. 7개의 데이터를 입력받아서
//그 중 최대값과 최소값을 제외한 합을 출력
#include <stdio.h>

int main() {
	int A_arr[10], tot=0;
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
		tot += A_arr[i];
	}
	printf("최대값과 최소값을 제외한 합 == %d ", tot-*max-*min);
}