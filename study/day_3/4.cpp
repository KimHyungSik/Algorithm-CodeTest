#include <stdio.h>

int print(int(*arr)[5]);

int main(){
  int arr[5][5] = { 0 };
  int count = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j <= i; j++){
      int t = i-j;
      if(t<5&&j<5){
        count++;
        arr[j][t] = count;
      }
    }
  }
  print(arr);
}
int print (int(*arr)[5]){
   for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 0)
				printf("   ");
			else printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
}