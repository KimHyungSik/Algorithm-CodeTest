#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000

using namespace std;

vector<pair<int, int>>graph[20001];// �׷��� <������, ����>
int answer[20001];      // ��ǥ ������ �Ÿ�
int V, E;               // ������, ������
int target;             // ��ǥ ��

void bfs(){
  priority_queue<pair<int,int>> q;
  q.push(make_pair(0, target));
  
  
  while(!q.empty()){
    // �� ���� �� ���
    int cost = -q.top().first;     // ����
    int s = q.top().second;        // �����
    q.pop();

    for(int i = 0; i < graph[s].size(); i++){
      int temp = graph[s][i].first;       // ����
      int sum = cost + graph[s][i].second;// ���� ������ �� ����
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

  answer[target] = 0;     // �ڽŰ��� �Ÿ� 0���� �ʱ�ȭ

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