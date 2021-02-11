#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001

using namespace std;

int N, M;
int arr[MAX];
vector<int>v[MAX];
vector<int>result;

// 위상 정렬
void topologi(){
  queue<int>q;
  for(int i = 1; i <= N; i++){
    if(!arr[i]){
      q.push(i);
    }
  }

  while(!q.empty()){
    int num = q.front();
    q.pop();
    result.push_back(num);

    for(int x : v[num]){
      arr[x]--;
      // 이전 간선이 없다면 추가
      if(!arr[x])
        q.push(x);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 0; i < M; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    // 간선 연결
    v[x].push_back(y);
    // 이전 간선 추가
    arr[y]++;
  }

  topologi();

  for(int x : result)
    printf("%d ", x);

  return 0;
}