#include <iostream>

using namespace std;

int N[10000001];

int MIN(int x, int y){
  return x < y ? x : y;
}

int main() {
  int n;
  scanf("%d", &n);
  N[1] = 0;
  N[2] = 1;
  N[3] = 1;

  for(int i = 4; i <= n; i++){
    N[i] = N[i-1]+1;
    if(!(i % 3)){
      N[i] = MIN(N[i/3]+1, N[i]);
    }
    
    if(!(i % 2)){
      N[i] = MIN(N[i/2]+1, N[i]);
    }
  }

  printf("%d", N[n]);

  return 0;
}