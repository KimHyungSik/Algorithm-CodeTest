#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int N, n, m;
  int dp[31][31];
  memset(dp, 0, sizeof(dp));
  scanf("%d", &N);
  for(int i = 1; i <= 30; i++) dp[1][i] = i;
  for(int i = 2; i <= 30; i++){
    for(int j = i; j<=30; j++){
      for(int k = j-1; k >= 1; k--){
        dp[i][j] += dp[i-1][k];
      }
    }
  }
  for(int i = 0; i < N; i++){
    scanf("%d %d", &n, &m);
    printf("%d\n", dp[n][m]);
  }

  return 0;
}