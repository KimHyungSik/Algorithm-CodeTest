#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

vector<pair<int, int>>graph[20001];// 그래프 <도착점, 가격>
int answer[20001];      // 목표 값에서 거리
int V, E;               // 정점수, 간선수
int target;             // 목표 값

void bfs(){
  priority_queue<pair<int,int>> q;
  q.push(make_pair(0, target));
  
  
  while(!q.empty()){
    // 맨 앞의 값 출력
    int cost = -q.top().first;     // 가격
    int s = q.top().second;        // 출발점
    q.pop();

    for(int i = 0; i < graph[s].size(); i++){
      int temp = graph[s][i].first;       // 정점
      int sum = cost + graph[s][i].second;// 정점 까지의 총 가격
      if(answer[temp] > sum){
        answer[temp] = sum;
        q.push(make_pair(-sum,temp));
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>V>>E;
  cin>>target;

  for(int i = 1; i <= V; i++){
    answer[i] = INF;
  }

  answer[target] = 0;     // 자신과의 거리 0으로 초기화

  for(int i = 0; i < E; i++){
    int u, v, w;
    cin>>u>>v>>w;
    graph[u].push_back(make_pair(v, w));
  }

  bfs();

  for(int i = 1; i <= V; i++){
    if(answer[i] != INF){
      printf("%d\n", answer[i]);
    }else{
      printf("INF\n");
    }
  }
  return 0;
}