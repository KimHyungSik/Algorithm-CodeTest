#include <iostream>
#include <algorithm>

using namespace std;

int min(int x, int y){
  return x < y ? x : y;
}

int main() {
  int N;
  long long M;
  int map[10001];

  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    scanf("%d", &map[i]);
  }
  scanf("%lli", &M);

  int low = 0;
  int high = *max_element(map, map+N);
  int mid;
  int result;
  while(low <= high){
    mid = (low + high)/2;
    long long temp = 0;
    for(int i = 0; i < N; i++)
      temp += min(mid,map[i]);
    if(temp <= M){
      low = mid + 1;
      result = mid;
    }else{
      high = mid -1;
    }
  }

  printf("%d\n", result);

  return 0;
}