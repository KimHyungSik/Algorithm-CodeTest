#include <iostream>

using namespace std;

int wine[10001] = {0,};
int dparr[10001] = {-1};

int max(int x, int y, int z){
  return x > y ? x > z ? x : z : y > z ? y : z;
}

int dp(int n){
  if(dparr[n] != -1 ) return dparr[n];
  return dparr[n] = max(dp(n-1), wine[n]+ dp(n-2), wine[n] + wine[n-1]+ dp(n-3));
}

int main() {
  int n;
  cin>>n;
  fill_n(dparr, 10001, -1);

  for(int i = 0; i < n; i++)
    scanf("%d", &wine[i+1]);
  dparr[1] = wine[1];
  dparr[2] = wine[1] + wine[2];
  dparr[3] = max(dparr[2], wine[3]+dparr[1], wine[3] + wine[2]);
  cout<<dp(n);
  return 0;
}