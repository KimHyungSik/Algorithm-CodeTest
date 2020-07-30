#include <iostream>

using namespace std;

int answer[100001] = {0};

int compare(int x, int y){
  return x > y ? y : x;
}

int solve(int x){

  
  if(answer[x]) return answer[x];
  else{
    if(!(x%3)){
      answer[x] = answer[x] ? compare(answer[x], solve(x/3)+1) :solve(x/3)+1;
    }
    if(!(x%2)){
      answer[x] = answer[x] ? compare(answer[x], solve(x/2)+1) : solve(x/2)+1;
    }
    answer[x] = answer[x] ? compare(answer[x], solve(x-1)+1) :solve(x-1)+1;
  }
  return answer[x];
}

int main() {
  int n;
  answer[1] = 0;
  answer[2] = 1;
  answer[3] = 1;
  cin>>n;
  cout<<solve(n);
}
