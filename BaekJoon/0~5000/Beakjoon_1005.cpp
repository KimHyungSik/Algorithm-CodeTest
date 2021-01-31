#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int N, K;

int topology(bool graph[1001][1001],int time_[1001], int inD[1001], int target){
  deque<int> t;
  int result[1001];
  //���� �𸣰ڴµ� result���� ����
  memset(result, 0, sizeof(result));

  for(int i = 1;i <= N; i++){
    if(!inD[i]){//���������� 0�� �� �˻�
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
          //���ε��� ���� ���� �� ��
          result[i] = result[i] > result[temp] + time_[i] ? result[i] : result[temp] + time_[i];
          if(!--inD[i]){// �������� ����
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

    //���� ������ ���� �������� ����
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