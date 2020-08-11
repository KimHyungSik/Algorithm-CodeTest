#include <iostream>

using namespace std;

int answer[12];

int solve(int x){  
  if(answer[x]) return answer[x];
  answer[x] = solve(x-1) + solve(x-2) + solve(x-3);
  return answer[x];
}

int main() {
  answer[1] = 1;
  answer[2] = 2;
  answer[3] = 4;
  int roop;
  int input;
  scanf("%d", &roop);
  for(int x = 0; x < roop; x++){
    scanf("%d", &input);
    printf("%d\n", solve(input));
  }
}
