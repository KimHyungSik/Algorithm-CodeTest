#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
  string str;
  cin>>str;
  vector<int>num;
  vector<char>op;
  bool flag =false;
  int temp = 0;
  for(int i = 0;i <= str.length() ;i++){
    if(isdigit(str[i])){
      temp *= 10;
      temp += str[i] - '0'; 
    }else{
      if(str[i] == '-') flag = true;
      op.push_back(str[i]);
      num.push_back(temp);
      temp = 0;
    }
  }
  int result = 0;
  if(!flag){
    for(int x : num) result += x;
    cout<<result<<endl;
    return 0;
  }
  int i = 0;
  while(!op.empty()){
    if(op[0] == '+'){
      temp = num[i];
      temp += num[i+1];
      num.erase(num.begin()+i);
      num.erase(num.begin()+i);  
      num.insert(num.begin()+i, temp);
      i--;
    }
    op.erase(op.begin());
    i++;
  }

  result = num[0] * 2;
  for(int x : num) result -= x;
  cout<<result<<endl;
  return 0;
}