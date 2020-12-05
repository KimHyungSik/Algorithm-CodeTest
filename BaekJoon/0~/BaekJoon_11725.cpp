#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> Tree;
vector<int> Root;
int N;

void RootNode(int Node){
  if(Tree[Node].empty()) return;
  for(int i = 0; i < Tree[Node].size(); i++){
    if(!Root[Tree[Node][i]]){
    Root[Tree[Node][i]] = Node;
    RootNode(Tree[Node][i]);}
  }
}

int main() {
  cin >> N;
  Tree = vector<vector<int>>(N+1, vector<int>());//총 크기 N의 자식루트 가 들어갈 vector 생성
  Root = vector<int>(N+1);
  for(int i = 0; i< N-1; i++){
    int a, b;
    cin >> a >> b;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
  }

  RootNode(1);

  for(int i = 2; i < N+1; i++){
    printf("%d\n", Root[i]);
  }

  return 0;

}