#include <iostream>
#include <stack>
using namespace std;

int com[101][101] = {0,};
int visited[101];
stack<int> virus;


int main() {
  int x, y, count=0;
  int tempx, tempy;
  cin>>x>>y;

  for(int i = 0;i < y;i++){
    scanf("%d %d", &tempx, &tempy);
    com[tempx][tempy] = com[tempy][tempx] = 1;
  }
  
  virus.push(1);
  visited[1] = 1;
  while(!virus.empty()){
    count++;
    tempx = virus.top();
    virus.pop();
    for(int i = 0; i <= x;i++){
      if(com[tempx][i]&& !visited[i]){
        virus.push(i);
        visited[i] = 1;
      }
    }
  }
  cout<<count-1;
}