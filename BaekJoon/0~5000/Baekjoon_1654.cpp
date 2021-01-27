#include <iostream>
#include <vector>

using namespace std;

int MAX(int x, int y){
  return x > y ? x : y;
}

int main() {
 int N, K;
 int temp, cut = 0;
 long long high = 0;
 long long row = 1;
 vector<int> lan;

 scanf("%d %d", &K, &N);

 for(int i = 0; i < K; i++){
   scanf("%d", &temp);
   lan.push_back(temp);
   high = MAX(high, temp);
 } 
 int result = 0;

  while(row <= high){
    long long mid = (high + row)/2;
    cut = 0;

    for(int i : lan){
      cut += i/mid;
    }
    if(cut >= N){
      result = result < mid ? mid : result;
    }
    if(cut < N){
      high = mid-1;
    }else{
      row = mid+1;
    }

  }
  printf("%d", result);
  return 0;
}