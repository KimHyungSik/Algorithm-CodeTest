#include <iostream>
using namespace std;

int max(unsigned int x, unsigned int y){
  return x > y ? x : y;
}

int main(){
  unsigned int N;

  scanf("%d", &N);

  unsigned int s = 1;
  unsigned int e = N/2+1;
  unsigned int result = 0;
  while(s <= e){
    unsigned int mid = (s+e)/2;
    long long sum = 0;
    for(unsigned int i = mid; i > 0;i--){
      sum += i;
      if(sum > N)break;  
    }

    if(sum <= N){
      result = max(result, mid);
      s = mid + 1;
    }else{
      e = mid - 1;
    }
  }

  printf("%d", result);

  return 0;
}