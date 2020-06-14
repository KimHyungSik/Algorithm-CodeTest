#include <stdio.h>
#include <math.h>

int main() {
	int arr[5][5] = { 0 };
	int(*a)[5] = arr;
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = -abs(i - 2) + 2; j < abs(i - 2) + 3; j++) {
			count++;
			*(*(a + i) + j) = count;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (*(*(a + i) + j) == 0) {
				printf("  ");
			}
			else if (*(*(a + i) + j) < 10) {
				printf("%d  ", *(*(a + i) + j));
			}
			else if (*(*(a + i) + j) >= 10) {
				printf("%d ", *(*(a + i) + j));
			}
		}
		printf("\n");
	}
}