#include <iostream>

using namespace std;

int count[5001];

void dp(int n){
  for(int i = 6; i <= n; i++){
    if(i % 3 == 0){
      count[i] = i/3;
    }
    if(i % 5 == 0){
      count[i] = i/5;
    }
    if(count[i - 5] != 0){
      count[i] = count[i-5]+1;
    }
    if(count[i -3] != 0){
      count[i] = count[i-3]+1;
    }
    if((i%5)%3 == 0){
      count[i] = count[i-5] +1;
    }
  }
}

int main(void){
  count[3] = 1;
  count[5] = 1;
  int goal;
  cin>> goal;
  dp(goal);

  goal = count[goal] == 0 ? -1 : count[goal];

  cout<<goal;

  return 0;
}