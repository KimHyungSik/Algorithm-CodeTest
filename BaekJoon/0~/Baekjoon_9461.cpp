#include <iostream>

int main(){
  int N;
  long long P[101];

  int T;
  scanf("%d", &T);
  P[1] = 1;
  P[2] = 1;
  P[3] = 1;
  P[4] = 2;
  P[5] = 2;
  for(int i = 6; i <= 100;i++){
    P[i] = P[i-1] + P[i-5];
  }
  for(int i = 0; i <T; i++){
    scanf("%d", &N);
    printf("%lli\n", P[N]);
  }

  return 0;
}