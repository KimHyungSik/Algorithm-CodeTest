//7. 7���� �����͸� �Է¹޾Ƽ�
//�� �� �ִ밪�� �ּҰ��� ������ ���� ���
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
	printf("�ִ밪�� �ּҰ��� ������ �� == %d ", tot-*max-*min);
}