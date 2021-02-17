#include <iostream>

using namespace std;

int main() {
  int N;
  long long map[11][1001];
  long long dp[1001];
  for(int i =0;i <10;i++){
    map[i][1] = 1;
  }
  dp[1] = 10;
  scanf("%d",&N);
  for(int i = 2; i <= N; i++){
    for(int j = 0; j <10; j++){
      for(int k = j; k<10;k++){
        map[j][i] = (map[j][i] + map[k][i-1])%10007;
      }
      dp[i]= (dp[i] + map[j][i])%10007;
    }
  }
  printf("%lli", dp[N]%10007);
}

