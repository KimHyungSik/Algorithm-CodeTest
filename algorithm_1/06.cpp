//6. 10���� �����͸� �Է¹޾Ƽ�
//�� �߿��� 90 �̻��� �������� ������ ���� ���ؼ� ���

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
	printf("90�̻��� ���� = %d, �հ� == %d\n", cnt, tot);
}