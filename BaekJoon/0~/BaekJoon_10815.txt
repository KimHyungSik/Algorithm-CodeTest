#include <iostream>
#include <algorithm>

using namespace std;

int card[500001];
int pred[500001];

bool find(int x,int max){
  int left = 0;
  int right = max -1;
  int mid;
  while(left <= right){
    mid = (right+left)/2; 
    if(x < card[mid]){
      right = mid-1;
    }else if(x>card[mid]){
      left = mid+1;
    }else if(x == card[mid]){
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, m, temp;
  cin >> n;
  for(int i = 0; i < n; i++)
    scanf("%d",&card[i]);
  sort(card,card+n);

  cin>>m;
  
  for(int i = 0; i < m; i++){
    scanf("%d", &temp);
    pred[i] = find(temp, n);
  } 

   for(int i = 0; i < m; i++){
    printf("%d\n", pred[i]);
  } 
  return 0;
}