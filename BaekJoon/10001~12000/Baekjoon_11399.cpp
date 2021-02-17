#include <iostream>
#include <deque>

using namespace std;

void switch_xy(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  
  int N;
  int temp;
  int min = 1001;
  int P[1001];

  scanf("%d", &N);

  for(int i = 0; i < N;i++){
    scanf("%d", P+i);
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
       if(P[i] < P[j]){
         switch_xy(&P[i], &P[j]);
       }
    }
  }

  int result = 0;
  for(int i = 0; i < N; i++){
    result += P[i];
    for(int j = 0; j < i; j++){
      result += P[j];
    }
  }

  printf("%d", result);

}