//3. �迭 C = �迭 A + �迭 B
//�迭�� ũ��� 10��
//c = a + b;

#include <stdio.h>

int main() {
	extern int A_arr[], B_arr[];
	int C_arr[10];
	for (int i = 0; i < 10; i++) {
		C_arr[i] = A_arr[i] + B_arr[i];
	}
	for (int i = 0; i < 10; i++) {
		printf("%d", C_arr[i]);
	}

}