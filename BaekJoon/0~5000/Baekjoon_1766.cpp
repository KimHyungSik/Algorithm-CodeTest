#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

int N, M;           // ������, ���� ������ ���� ��
int topol[MAX];     // ���� ���Ŀ� ���� 
vector<int>v[MAX];  // ���� Ȯ��
vector<int>c;       // ���� ����

int main(){
  scanf("%d %d", &N, &M);

  for(int i = 0; i < M; i++){
    int x ,y;
    scanf("%d %d", &x, &y);
    topol[y]++;
    v[x].push_back(y);
  }

  // ���� ������ ���� Ǯ������ �켱���� ť ���
  // ���� ���� ������ �ϱ� ���� -�����Ͽ� ���
  priority_queue<int>q;

  for(int i = 1; i <= N; i++){
    if(!topol[i])q.push(-i);
  }
  
  // ���� ����
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