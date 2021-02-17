#include <iostream>
#include <cstring>
using namespace std;

int MAX(int x, int y){
  return x > y? x : y;
}

int main() {
  int T,N;
  int map[2][100001];
  int DP[2][100001];
  int dp[100001];
  cin>>T;
  memset(map, 0, sizeof(map));
  memset(DP, 0, sizeof(DP));
  for(int t =0; t< T;t++){

    cin>>N;
    for(int i = 0;i < 2;i++){
      for(int j = 0;j < N;j++){
        cin>>map[i][j];
      }
    }
    DP[0][0] = map[0][0];
    DP[1][0] = map[1][0];
    dp[0] = MAX( DP[0][0],DP[1][0]);

    DP[0][1] = map[1][0] + map[0][1];
    DP[1][1] = map[0][0] + map[1][1];
    dp[1] = MAX(DP[0][1],DP[1][1]);

    for(int i = 2; i <N;i++){
      DP[0][i] = MAX(DP[1][i-1] + map[0][i], dp[i-2]+map[0][i]);
      DP[1][i] = MAX(DP[0][i-1] + map[1][i], dp[i-2]+map[1][i]);
      dp[i] = MAX(DP[0][i],DP[1][i]);
    } 

    cout<<dp[N-1]<<endl;
  }

}
