#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  char result1[8][8];
  char result2[8][8];
  for(int i = 0; i < 8;i++){
    for(int j = 0; j < 8;j++){
      if(i%2){
        if(j%2){
          result1[i][j] = 'B';
          result2[i][j] = 'W';
        }else{
          result1[i][j] = 'W';
          result2[i][j] = 'B';
        }
      }else{
        if(j%2){
          result1[i][j] = 'W';
          result2[i][j] = 'B';
        }else{
          result1[i][j] = 'B';
          result2[i][j] = 'W';
        }
      }
    }
  }

  int N,M;
  char *c_ptr;
  char MAP[51][51];
  vector<int> result;
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N;i++){
    scanf("%s", MAP[i]);
  }

  for(int i = 0; i < N-7; i++){
    for(int t = 0; t< M-7;t++){
      int count1 = 0;
      int count2 = 0;
      for(int j = i; j < i+8;j++){
        for(int k = t; k < t+8;k++){
          if(MAP[j][k] != result1[j-i][k-t]){
            count1++;
          }
          if(MAP[j][k] != result2[j-i][k-t]){
            count2++;
          }
        }
      }
      result.push_back(count1);
      result.push_back(count2);
    }
  }

  sort(result.begin(), result.end());
 printf("%d", result[0]);
  return 0;
}