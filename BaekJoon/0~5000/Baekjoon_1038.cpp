#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int N;
  long long number = 0;
  int count = 0;
  scanf("%d", &N);
  
  int n;
  long long temp;
  bool check = true;
  int up_count;
  int num_count;
  if(N > 1022){
    printf("-1");
    return 0;
  }

  while(count < N){
    if(check){
      number++;
    }else{
      number += (int)pow(10, up_count);
      number -= number % (int)pow(10, up_count);
    }
    temp = number;
    check = true;
    up_count = 0;
    num_count = 0;
    while(temp > 10){
      n = temp%10;
      temp = temp / 10;
      num_count++;
      if(temp % 10 <= n ){
        check = false; 
        up_count = num_count;
      }
    }
    if(check){
      count++;
    }
  }
  printf("%lli", number);
  return 0;
}