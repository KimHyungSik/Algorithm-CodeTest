#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
 map<string, int> notLook;
 int n=0;
 int m=0;
 int count =0 ;
 string name;
 vector<string>namedes;
 cin>>n>>m;
for(int i = 0; i < m; i++){
    cin>>name;
    notLook.insert(make_pair(name,1));
 }

 for(int i = 0; i < n; i++){
   cin>>name;
   if(notLook.find(name)!= notLook.end()){
     count++;
    namedes.push_back(name);
   }
 }

 sort(namedes.begin(), namedes.end());
 cout<<count<<endl;
  for(auto namede : namedes ){
    cout<<namede<<"\n";
  }
  return 0;
}