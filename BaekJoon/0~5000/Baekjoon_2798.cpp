#include <iostream>
#include <string.h>
using namespace std;

int N, M;
int max_card = 0;
int card[101];

int MAX(int x, int y){
  return x > y ? x : y;
}

int main() {
  
  scanf("%d %d", &N, &M);
  
  for(int i = 0; i < N; i++){
    scanf("%d", &card[i]);
  }
  int temp;
  int temp3;
  for(int i = 0; i < N;i++){
    for(int j = 0; j < N; j++){
      temp = card[i] + card[j];
      if(temp > M || j == i){
        continue;
      }
      for(int k =0; k < N; k++){\
        temp3 = temp + card[k];
        if(k == i || k ==j ||temp3 > M){
          continue;
        }
        max_card = MAX(max_card, temp3);
      }
    }
  }
  printf("%d", max_card);

  return 0;
}