#include <iostream>

using namespace std;

int n;
int m;

bool areFriends [10][10];

int countPairings(bool taken[10]){
  int firstFree = -1;
  for(int i = 0; i < n ;i++){
    if(!taken[i]){
      firstFree = i;
      break;
    }
  }
  if(firstFree == -1) return 1;
  int ret = 0;
  for(int pairWith = firstFree; pairWith < n;++pairWith){
    if(!taken[pairWith] && areFriends[firstFree][pairWith]){
      taken[firstFree] = taken[pairWith] = true;
      ret += countPairings(taken);
      taken[firstFree] = taken[pairWith] = false;
    }
  }
  return ret;
}

int main() {
  cin >> n;
  cin >> m;
  for(int i = 0; i < m;i++){
    int y, x;
    cin >> x;
    cin >> y;
    areFriends[x][y] = true;
  }
  bool taken[10] = {0,};
  cout << countPairings(taken)<<endl;
}