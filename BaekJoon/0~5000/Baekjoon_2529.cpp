#include <iostream>

using namespace std;

int N;
char k[10];
char mi[11], mx[11];
bool visited[10];
long long MIN = 10000000000, MAX = 0; 

void dfs(long long arr, int index){
  if(index == N+1){
    MIN = MIN > arr ? arr : MIN;
    MAX = MAX > arr ? MAX : arr;
    return;
  }
  for(int i = 0; i < 10; i++){
    if(k[index-1] == '<'){
      if(!visited[i] && arr%10 < i){
        visited[i] = true;
        dfs((arr * 10) + i, index+1);
        visited[i] = false;
      }
    }else if(k[index-1] == '>'){
      if(!visited[i] && arr%10 > i){
        visited[i] = true;
        dfs((arr * 10) + i, index+1);
        visited[i] = false;
      }
    }
  }
}

int main(){
  long long ten = 1;
  scanf("%d",&N);
  for(int i = 0; i < N;i++){
    cin>>k[i];
    ten *= 10;
  }

  for(int i = 0; i < 10; i++){
    visited[i] = true;
    dfs(i, 1);
    visited[i] = false;
  }

 for(int i = N; i >= 0; i--){
   mi[i] = (MIN % 10) + '0';
   mx[i] = (MAX % 10) + '0';
   MIN /= 10;
   MAX /= 10;
 }
 mi[10] = '\0';
 mx[10] = '\0';
 printf("%s\n%s", mx, mi);
 return 0;
}