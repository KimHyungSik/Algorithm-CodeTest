#include <iostream>

int main() {
  int N;
  int count = 99;
  scanf("%d", &N);

  int f, s, t, temp;
  if(N < 100){
    printf("%d", N);
    return 0;
  }

  for(int i = 100; i <= N; i++){
    temp = i;
    f = temp % 10;
    temp = temp / 10;
    s = temp % 10;
    t = temp / 10;
    if((t-s) == (s-f)){
      count++;
    }
  }

  printf("%d", count);
  return 0;
}