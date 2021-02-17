#include <iostream>
#include <algorithm>
using namespace std;

int max(int x, int y){return x > y ? x : y;}


int main() {
  int n;
  int temp;
  int a[501][501];
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      cin >> temp;
      a[i][j] = temp;
    }
  }
  
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= i; j++){
      if(!j) a[i][j] += a[i-1][j];
      else if(j == i) a[i][j] += a[i-1][j-1];
      else a[i][j] = max(a[i][j] + a[i-1][j-1], a[i][j] + a[i-1][j]); 
    }
  }

 cout<< *max_element(a[n-1],a[n-1] + n);
}
