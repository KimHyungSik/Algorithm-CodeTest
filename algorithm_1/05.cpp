//5. 10개의 데이터를 입력받아서 배열에 저장하고
//MAX와 MIN을 구하시오

#include <stdio.h>

int main() {
	int A_arr[10];
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
	printf("MAX == %d, MIN == %d\n", *max, *min);
}