#include <iostream>

int N, result;
int xp[16], yp[16];
int bfs(int y, int x){
  int r = 0;

  for(int i = 0; i < y; i++){
    if(x == xp[i]) return 0;
    if(abs(x - xp[i]) == abs(y - yp[i])) return 0;
  }
  
  if(y == N-1){
    return 1;
  }

  xp[y] = x; yp[y] = y;

  for(int i = 0; i < N;i++){
    r += bfs(y+1, i);
  }

  return r;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; i ++){
    result += bfs(0, i);
  }
  printf("%d", result);
  return 0;
}
