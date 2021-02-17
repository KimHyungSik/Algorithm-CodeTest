#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  int result = 0;
  int temp;
  vector<int> price;
  scanf("%d %d", &N, &K);

  for(int i = 0; i < N;i++){
    scanf("%d", &temp);
    price.push_back(temp);
  }

  for(int i = N-1; i >= 0 ; i--){
      result+= K / price[i];
      K = K % price[i];
  }

  printf("%d", result);

  return 0;
}