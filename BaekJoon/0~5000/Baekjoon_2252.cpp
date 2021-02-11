#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001

using namespace std;

int N, M;
int arr[MAX];
vector<int>v[MAX];
vector<int>result;

// ���� ����
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
      // ���� ������ ���ٸ� �߰�
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
    // ���� ����
    v[x].push_back(y);
    // ���� ���� �߰�
    arr[y]++;
  }

  topologi();

  for(int x : result)
    printf("%d ", x);

  return 0;
}