#include <stdio.h>
#include <math.h>

int main() {
	int arr[7][7] = { 0 };
	int(*a)[7] = arr;
	int count = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < abs(i - 3) + 4; j++) {
			count++;
			*(*(a + i) + j) = count;
		}
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
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