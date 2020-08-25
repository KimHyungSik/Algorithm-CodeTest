#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int M[27][27] = {0,};
vector<int>address;
int cnt=0;
bool visited[27][27]={false,};

void dfs(int x,int y){
  if(x > 0 && y >0 && M[y][x] == 1 && !visited[y][x]){
    visited[y][x] = true;
    cnt++;
    for(int i = 0;i<4;i++){
      dfs(x+dx[i],y+dy[i]);
    }
  }else{
    return;
  }
}

int main() {
  int n, temp;

  cin>>n;
  for(int i = 1; i <= n; i++){
    for(int j = 1;j <= n; j++){
      scanf("%1d",&M[i][j]);
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1;j <= n; j++){
      cnt = 0;
      if(M[i][j] == 1 && !visited[i][j]){
        dfs(j,i);
        address.push_back(cnt);
      }
    }
  }
  sort(address.begin(),address.end());
  cout<<address.size()<<endl;
  for(int x = 0;x<address.size();x++){
    cout<<address[x]<<endl;
  }
}
