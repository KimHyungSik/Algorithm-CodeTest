
#include <stdio.h>

#define COL 3
#define ROW 5

void print(int (*arr)[COL],int row,int col);

int main() {
	int arr[ROW][COL] = { 0 };
  int count = 1;
  printf("row = %d   col = %d\n", sizeof(arr)/sizeof(arr[0]), sizeof(arr[0])/sizeof(arr[0][0]));
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
    for(int j = 0; j < sizeof(arr[0])/sizeof(arr[0][0]);j++){
      arr[i][j] = count++;
    }
  }
  print(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0])/sizeof(arr[0][0]));
  count = 1;
  printf("\n");
  for(int i = 0; i <sizeof(arr[0])/sizeof(arr[0][0]) ;i++){
    for(int j = 0; j < sizeof(arr)/sizeof(arr[0]);j++){
      arr[i][j] = count++;
    }
  }
  print(arr, sizeof(arr[0])/sizeof(arr[0][0]), sizeof(arr)/sizeof(arr[0]));
}

void print(int (*arr)[COL],int row,int col){
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] == 0)
        printf("   ");
      else printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}