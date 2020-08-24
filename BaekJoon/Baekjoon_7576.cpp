#include<iostream>
#include <deque>

using namespace std;

int box[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
deque<pair<int,int>>Fresh;
int day=-1;
int n, m;

void Freshtomato(){
  int temp = Fresh.size();
  int tempX,tempY;
  for(int x = 0; x <temp; x++){
    for(int i = 0; i < 4; i++){
      tempY = Fresh[0].first + dy[i];
      tempX = Fresh[0].second + dx[i];
      if(tempY != 0 && tempX != 0 && tempY <= m && tempX <= n && box[tempY][tempX] == 0){
        box[tempY][tempX] = 1;
        Fresh.push_back(make_pair(tempY,tempX));
      }
    }
    Fresh.pop_front();
  }
}

void tomatobox(){
  while(!Fresh.empty()){
    day++;
    if(!Fresh.empty()){
        Freshtomato();
    }
  }
}

int print(){
  for(int i = 1; i <= m; i++){
    for(int j = 1;j <= n; j++){
      if(!box[i][j]){
        return -1;
      }
    }
  }
  return day;
}

int main() {
  cin>>n;
  cin>>m;
  for(int i = 1; i <= m; i++){
    for(int j = 1;j <= n; j++){
      scanf("%d",&box[i][j]);
    }
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1;j <= n; j++){
     if(box[i][j] == 1){
       Fresh.push_back(make_pair(i,j));    
     }
    }
  }
  tomatobox();

  cout<< print();

}
