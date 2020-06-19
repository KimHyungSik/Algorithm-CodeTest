#include <stdio.h>

int main() {
	int arr[5][5] = { 0 };
	int count = 0;
	for (int i = 4; i >= 0; i--) {
		for (int j = i; j < 5; j++) {
			count++;
			arr[i][j] = count;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 0)
				printf("   ");
			else printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
}

