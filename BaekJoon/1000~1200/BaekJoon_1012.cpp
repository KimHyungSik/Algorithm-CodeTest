#include <iostream>
#include <vector>
using namespace std;

int map[51][51] = {0};
int visited[51][51] = {0};
int i = 1;
int count = 0;
int test_case;
int max_x, max_y, cabbage;
vector<int> result;
void DFS(int x, int y){
  if(map[x][y] == i && visited[x][y] < i){
    visited[x][y] = i;
  }
  if(map[x+1][y] == i && visited[x+1][y] < i){
    DFS(x+1,y);
  }
  if(map[x][y+1] == i && visited[x][y+1] < i){
    DFS(x,y+1);
  }
  if(x > 0){
    if(map[x-1][y] == i && visited[x-1][y] < i){
      DFS(x-1,y);
    }
  }
  if(y > 0){
    if(map[x][y-1] == i && visited[x][y-1] < i){
      DFS(x,y-1);
    }
  }
}

void need_worm(){
  int x_, y_;
  count = 0;
  for(int j = 0; j < cabbage; j++){
    scanf("%d %d", &x_, &y_);
    map[x_][y_] = i;
  }
  for(int j = 0; j < max_x; j++){
    for(int k = 0; k < max_y; k++){
      if(map[j][k] == i && visited[j][k] < i){
        count++;
        DFS(j,k);    
      }
    }
  }
  result.push_back(count);
}

int main() {
  scanf("%d", &test_case);
  for(i = 1; i <= test_case;i++){
    scanf("%d", &max_x);
    scanf("%d", &max_y);
    scanf("%d", &cabbage);
    need_worm();
  }
  for(int j = 0; j < result.size(); j++){
    printf("%d\n", result[j]);
  }
  return 0;
}

