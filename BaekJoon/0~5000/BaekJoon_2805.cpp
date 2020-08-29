#include <iostream>
#include <algorithm>

long long MAX(long long x, long long y){
  return x > y ? x : y;
}

long long a[1000002];

int main() {
 long long n,m;
 long long min,max = 0;
 long long high,sum,mid,result;
 long long low = 0;

 scanf("%lld %lld",&n, &m);

  for(long long i = 0; i < n;i++){
    scanf("%lld", &a[i]);
    max = MAX(a[i],max);
  }

  std::sort(a,a+n);

  high = max;

  while(low <= high){
    sum = 0;
    mid = low + (high-low)/2;
    for(long long i = 0;i<n;i++){
      sum += MAX(a[i]-mid,0);
    }
    if(sum < m) high = mid -1;
    else if(sum == m) {result = mid; break;}
    else if(sum >= m) {result = mid;low = mid+1;}
  }

  printf("%lld", result);
}