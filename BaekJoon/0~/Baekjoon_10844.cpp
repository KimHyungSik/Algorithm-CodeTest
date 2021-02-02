#include <iostream>

int main() {
  int N;
  long long map[101][11] = {0,};
  long long result = 0;
  scanf("%d", &N);
  if(N == 1){
    printf("9");
    return 0;
  }
  for(int i = 0; i < 10; i++){
    map[0][i] = 1;
    map[1][i] = 1;
  }
  for(int i = 2; i <= N;i++){
    for(int j = 1; j < 10;j++){
      if(j == 1){
        map[i][j] = (map[i-2][j] + map[i-1][j+1])%1000000000;
      }else if(j == 9){
        map[i][j] = (map[i-1][j-1])%1000000000;
      }else{
        map[i][j] = (map[i-1][j-1] + map[i-1][j+1])%1000000000;
      }
    }
  }
  for(int i=0; i<10;i++){
    result += map[N][i];
  }
  printf("%lli", result%1000000000);
  return 0;

}