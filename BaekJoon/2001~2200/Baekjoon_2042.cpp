#include <iostream>
#define MAX 1000010

using namespace std;

long long arr[MAX];
long long result[MAX];
int N, M, K;

// 바이너리 인덱스 트리

long long sum(int index){
  long long re = 0;
  while(index > 0){
    re += result[index];
    index &= index-1;
  }
  return re;
}

long long rangeSum(int start, int end){
  long long re = sum(end);
  if(start > 0)
    re -= sum(start-1);
  return re;
}

void add(int pos, int num){
  while(pos<=N){
    result[pos] += num;
    pos += pos & -pos; 
  }
}

void update(int pos, long long num, int index){
  while(pos<=N){
    result[pos] += num - arr[index];
    pos += pos & -pos;
  }
}

int main(){

  scanf("%d %d %d", &N, &M, &K);

  for(int i = 1; i <= N; i++){ 
    scanf("%lli", &arr[i]);
    add(i, arr[i]);
  }

  while(M || K){
    int a, b;
    long long c;
    scanf("%d %d %lli", &a, &b, &c);
    if(a == 1){
      update(b, c, b);
      arr[b] = c;
      M--;
    }else{
      printf("%lli\n", rangeSum(b, c));
      K--;
    }
  }
  return 0;
}