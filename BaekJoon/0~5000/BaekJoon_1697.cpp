#include<iostream>
#include<deque>

using namespace std;
  
deque<pair<int,int>> que;
int n,k,front,second;
int visited[100001] = {0,};

int main(void) {
  cin>>n>>k;
  if(k<=n){cout<<n-k; return 0;}
  que.push_back(make_pair(n,0));
  visited[n] = 1;
  while(!que.empty()){
    front = que.front().first;
    second = que.front().second;
    if(front == k){cout<<second; return 0;};
    que.pop_front();
    if(!visited[front-1] && front-1 >= 0){
      visited[front-1] = 1;
      que.push_back(make_pair(front-1,second+1));
    }
    if(!visited[front+1] && front+1 <= 100000 ){
      visited[front+1] = 1;
      que.push_back(make_pair(front+1,second+1));
    }
    if( front*2 <= 100000){
      if(!visited[front*2] ){
        visited[front*2] = 1;
        que.push_back(make_pair(front*2,second+1));
      } 
    }
  }
}
