#include <iostream>

using namespace std;

int answer[1001];

int solve(int x){  
  if(x == 1) return x;
  if(x == 2) return x;
  if(answer[x] != 0) return answer[x];
  return answer[x] = (solve(x-1) + solve(x-2)) % 10007;
}

int main() {
  int input;
  scanf("%d", &input);
  printf("%d\n", solve(input));
}
