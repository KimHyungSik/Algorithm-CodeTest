//8. �л����� ���� S[20]���� �Է¹޾Ƽ�
//�ְ� ������ ���� ������ �ش��ϴ� �л��� ������� ���
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
	printf("�ְ��� �л� �� == %d, ������ �л� �� == %d\n", MAX_cnt, MIN_cnt);
}