//6. 10개의 데이터를 입력받아서
//그 중에서 90 이상인 데이터의 개수와 합을 구해서 출력

#include <stdio.h>

int main() {
	int A_arr[10], cnt=0, tot=0;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &A_arr[i]);
		if (A_arr[i] >= 90) {
			cnt++;
			tot += A_arr[i];
		}
	}
	printf("90이상인 개수 = %d, 합계 == %d\n", cnt, tot);
}