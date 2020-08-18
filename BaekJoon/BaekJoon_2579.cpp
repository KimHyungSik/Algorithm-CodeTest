#include <iostream>

using namespace std;

int result[301];
int stairs[301];
int n;

int max (int a, int b){
  return a > b ? a : b;
}

int dp(int x){
  if(result[x]) return result[x];
  result[x] = max(dp(x-2)+stairs[x], dp(x-3)+stairs[x-1] + stairs[x]);
  return result[x];
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> stairs[i+1];
  }
  result[1] = stairs[1];
  result[2] = stairs[1] + stairs[2];
  result[3] = max(stairs[1] + stairs[3],stairs[2] +stairs[3]);
  cout << dp(n);
}
