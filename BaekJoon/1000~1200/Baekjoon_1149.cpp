#include <iostream>

int tree_min(int x, int y, int z){
  return x < y ? x < z ? x : z : y < z ? y : z;
}
int two_min(int x, int y){
  return x < y ? x : y;
}

int main() {
  int home[3][1001];
  int R, G, B;
  int r, g, b;
  int n;

  scanf("%d", &n);
  scanf("%d %d %d", &R, &G, &B);

  if(n == 1){
    printf("%d", tree_min(R, G, B));
    return 0;
  }

  int P_R, P_G, P_B;
  home[0][0] = R;
  home[1][0] = G;
  home[2][0] = B;

  for(int i = 1; i < n; i++){
    scanf("%d %d %d", &R, &G, &B);
    P_R = home[0][i-1];
    P_G = home[1][i-1];
    P_B = home[2][i-1];

    r = R + two_min(P_G, P_B);
    g = G + two_min(P_R, P_B);
    b = B + two_min(P_G, P_R);

    home[0][i] = r;
    home[1][i] = g;
    home[2][i] = b;
  }

  printf("%d", tree_min(home[0][n-1], home[1][n-1], home[2][n-1]));

  return 0;
}