//1. 배열 A의 내용을 배열 B의 내용에 저장하시오
//
//A : 1 2 3 4 5 6 7 8 9 10
//B : 10 9 8 7 6 5 4 3 2 1
#include <stdio.h>

int main() {
	extern int A_arr[];
	int B_arr[10];

	for (int i = 0; i < 10; i++) {
		B_arr[i] = A_arr[9 - i];
	}
	for (int i = 0; i < 10; i++) {
		printf("%d  ", B_arr[i]);
	}

	printf("\n");
}