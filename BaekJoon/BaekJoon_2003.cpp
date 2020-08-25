#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n,m,temp;
  int front, end;
  int count = 0;
  vector<int>que;
  cin>>n>>m;
  if(n==0){cout<<count;return 0;}
  for(int i = 0; i < n; i++){
    cin>>temp;
    que.push_back(temp);
  }

  for(int i = 0; i < que.size();i++){
    temp = que[i];
    if(temp == m){count++; continue;}
    for(int j = i+1; j < que.size();j++){
      temp += que[j];
      if(temp == m){count++; break;}
      if(temp > m) break;
    }
  }

  cout<<count;

}
