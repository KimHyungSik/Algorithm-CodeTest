#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

int N, M;           // 문제수, 문제 난위도 설정 수
int topol[MAX];     // 위상 정렬용 간선 
vector<int>v[MAX];  // 연결 확인
vector<int>c;       // 정답 순서

int main(){
  scanf("%d %d", &N, &M);

  for(int i = 0; i < M; i++){
    int x ,y;
    scanf("%d %d", &x, &y);
    topol[y]++;
    v[x].push_back(y);
  }

  // 쉬운 문제를 먼저 풀기위해 우선순위 큐 사용
  // 낮은 수를 앞으로 하기 위해 -연산하여 사용
  priority_queue<int>q;

  for(int i = 1; i <= N; i++){
    if(!topol[i])q.push(-i);
  }
  
  // 위상 정렬
  while(!q.empty()){
    int now = q.top();
    now = -now;
    c.push_back(now);
    q.pop();

    for(int x : v[now]){
      topol[x]--;
      if(topol[x] <= 0){
        q.push(-x);
      }
    }
  }


  for(int x : c)printf("%d ", x);

  return 0;
}