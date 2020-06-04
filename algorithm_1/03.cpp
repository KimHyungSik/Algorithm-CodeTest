//3. 배열 A의 내용을 다음과 같이 변경
//
//A : 1 2 3 4 5 6 7 8 9 10
//A : 10 9 8 7 6 5 4 3 2 1

#include <stdio.h>
extern void temp(int*, int*);

int main() {
	extern int A_arr[];
	for (int i = 0; i < 5; i++) {
		temp(&A_arr[i], &A_arr[9 - i]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d  ", A_arr[i]);
	}

}

