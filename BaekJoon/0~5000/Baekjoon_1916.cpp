#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
#define INF 1000000000

using namespace std;

vector<pair<int, int>>v[MAX]; // 도착점, 가격
int N, M, start, en; // 도시개수, 버스 개수, 출발지, 도착 지점
int result[MAX];   

int main(){
  scanf("%d", &N);
  scanf("%d", &M);
  
  for(int i = 0; i < M; i++){
    int s, e, w;
    scanf("%d %d %d", &s, &e, &w);
    v[s].push_back(make_pair(e, w));
  }

  for(int i = 1; i <= N; i++) result[i] =INF;

  scanf("%d %d", &start, &en);

  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, start)); // 현재 cost, 현재 정점

  while(!q.empty()){
    int cost = -q.top().first;
    int cur = q.top().second;
    q.pop();
    for(int i = 0; i < v[cur].size();i++){
      int cur_ = v[cur][i].first;
      int cost_ = cost + v[cur][i].second;
      if(result[cur_] > cost_){
        result[cur_] = cost_;
        q.push(make_pair(-cost_, cur_));
      }
    }
  } 

  printf("%d", result[en]);
  return 0;
}