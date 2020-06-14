//3. 배열 C = 배열 A + 배열 B
//배열에 크기는 10개
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