#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int temp;
int n[51];
vector<int>m;
int n_max = 0, m_max = 0; 

int max(int x, int y){
  return x > y ? x : y;
}

bool com(int x, int y){
  return x > y ? true : false;
}

//lower 방식으로 자신과 최대치와 비슷한 무게 검색
int find(int x){
  int s = 0, e = m.size()-1;
  int re = -1;//들수 없는 경우 -1
  while(s <= e){
    int mid = (s+e)/2;
    if(m[mid] <= x){
      re = mid;
      s = mid +1;
    }else e = mid-1;
  }
  return re;
}

int main() {
  scanf("%d", &N);
  
  for(int i = 0; i < N; i++){
    scanf("%d", &n[i]);
    n_max = max(n_max, n[i]);
  }

  scanf("%d", &M);

  for(int i = 0; i < M; i++){
    scanf("%d", &temp);
    m.push_back(temp);
    m_max = max(m_max, temp);
  }
  if(n_max < m_max){
    printf("-1");
    return 0;
  }
  sort(n,n+N);
  sort(m.begin(),m.end());

  int result = 0;
  
  while(!m.empty()){
    result++;
    for(int i = 0; i< N;i++){
      if(m.empty())break;
      int find_ = find(n[i]);
      if(find_ != -1){
        m.erase(m.begin()+find_);
      }
    }
  }
  printf("%d", result);
  return 0;
}