#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int N, K;

int topology(bool graph[1001][1001],int time_[1001], int inD[1001], int target){
  deque<int> t;
  int result[1001];
  //왠지 모르겠는데 result값이 남음
  memset(result, 0, sizeof(result));

  for(int i = 1;i <= N; i++){
    if(!inD[i]){//진입차수가 0인 값 검색
      t.push_back(i);
      result[i] = time_[i];
    }
  }

  int temp;

  while(!t.empty()){
    temp = t.front();
    t.pop_front();

    for(int i = 1; i <= N; i++){
      if(graph[temp][i]){
          //새로들어온 값과 기존 값 비교
          result[i] = result[i] > result[temp] + time_[i] ? result[i] : result[temp] + time_[i];
          if(!--inD[i]){// 진입차수 차감
            t.push_back(i);
          }
      }
    }
  }
  return result[target];
}

void inputer(){
  bool graph[1001][1001] = {false,};
  int time_[1001] = {0,};
  int inD[1001] = {0,};
  int start, end, target;
    
  scanf("%d %d", &N, &K);

  for(int i = 1;i <= N;i++){
    scanf("%d", &time_[i]);
  }

  for(int i = 1;i <= K;i++){
    scanf("%d %d", &start, &end);
    graph[start][end] = true;

    //위상 정렬을 위한 진입차수 설정
    inD[end]++;
  }

  scanf("%d", &target);

  printf("%d\n", topology(graph, time_, inD, target));
}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 0; i < T;i++){
    inputer();
  }
  return 0;
}