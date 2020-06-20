
#include <stdio.h>

#define MAX 7

void print(int (*arr)[MAX]);

int main() {
	int arr[MAX][MAX] = { 0 };
  int x = MAX/2;
  int y = MAX-1;
  int count = 1;
  arr[y][x] = count++;
  while(count<=MAX*MAX){
    if(arr[y+1][x+1] == 0 && x+1 < MAX && y+1 < MAX){
      x++;y++;
      arr[y][x] = count++;
    }else if(arr[y+1][x+1] != 0 && x+1 < MAX && y+1 < MAX){
      y--;
      arr[y][x] = count++;
    }else if(x+1>=MAX || y+1>=MAX){
      if( x+1 >= MAX && y+1 >= MAX){
        y--;
        arr[y][x] = count++;
      }else if(x+1 >= MAX){
      y++;
        for(int i = 0; i<x; i++){
          if(arr[y][i] == 0){
            arr[y][i] = count++;
            x = i;
            break;
          } 
        }
      }else if(y+1 >= MAX){
        x++;
        for(int i = 0; i<y; i++){
          if(arr[i][x] == 0){
            arr[i][x] = count++;
            y = i;
            break;
          } 
        }
      }
    }
  }
  
   print(arr);
}

void print(int (*arr)[MAX]){
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (arr[i][j] == 0)
        printf("   ");
      else printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}