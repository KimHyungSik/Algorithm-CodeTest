#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b){
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main() {
  int N;
  int temp, temp2;
  vector<pair<int,int>> map;

  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    scanf("%d %d", &temp, &temp2);
    map.push_back(make_pair(temp, temp2));
  }

  sort(map.begin(), map.end(),compare);
  int result = 0;
  int now = map[0].first;
  for(int i = 0; i < N; i++){
    if(now <= map[i].first){
      now = map[i].second;
      result++;
    }
  }

  printf("%d", result);

  return 0;
}