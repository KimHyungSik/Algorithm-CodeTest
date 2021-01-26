#include iostream
#include vector

using namespace std;

vectorint N_express[9];

int min(int x, int y){
  return x  y  x  y;
}

int doubleing(int x, int y){
  int temp = x;
  for(int i = 1; i  y; i++){
    temp = (temp  10) + temp;
  }
  return temp;
}
int solution(int N, int number){
  if(N == number){
    return 1;
  }
  N_express[1].push_back(N);
  N_express[2].push_back(N + N);
  N_express[2].push_back(N - N);
  N_express[2].push_back(N  N);
  N_express[2].push_back(N  N);
  N_express[2].push_back(doubleing(N, 2));

  for(int i = 3; i = 8; i++){
    int temp = 1;
    N_express[i].push_back(doubleing(N, i));
    for(int j = 1; j  i; j++){
      for(int k = 0; k  N_express[j].size(); k++){
        for(int t = 0; t  N_express[i-j].size(); t++){
          N_express[i].push_back(N_express[j][k] + N_express[i-j][t]);
          N_express[i].push_back(N_express[j][k]  N_express[i-j][t]);
          if(N_express[j][k] && N_express[i-j][t]){
            N_express[i].push_back(N_express[j][k]  N_express[i-j][t]);
          }
          N_express[i].push_back(N_express[j][k] - N_express[i-j][t]);
        }
      }
    }
  }
  for(int i = 1; i = 8; i++){
    for(int j = 0; j  N_express[i].size(); j++){
      if(N_express[i][j] == number){
        return i;
      }
    }
  }

  return -1;
}

int main() {
 int N, number;
 scanf(%d %d, &N, &number);
 printf(%d, solution(N, number));
}