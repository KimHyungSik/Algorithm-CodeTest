#include <iostream>
#include <vector>

using namespace std;
int N;
const int MAX = 26;
int parent[MAX];
vector<vector<char>> Tree;

//전위 순회 
void preOrder(char root){
  if(root == '.')
    return;
  char left = Tree[root-'A'][0];
  char right = Tree[root-'A'][1];
  printf("%c",root);
  preOrder(left);
  preOrder(right);
}

//중위 순회
void InOrder(char root){
  if(root == '.')
    return;
  char left = Tree[root - 'A'][0];
  char right = Tree[root - 'A'][1];

  InOrder(left);
  printf("%c", root);
  InOrder(right);
}

//후위 순회
void postOrder(char root){
  if(root == '.')
    return;
  char left = Tree[root-'A'][0];
  char right = Tree[root - 'A'][1];

  postOrder(left);
  postOrder(right);
  printf("%c",root);
}

int main() {
  cin >> N;
  Tree = vector<vector<char>>(N, vector<char>());//총 크기 N의 자식루트 가 들어갈 vector 생성
  for(int i = 0; i< N; i++){
    char a, b, c;
    cin >> a >> b >> c;
    Tree[a-'A'].push_back(b);
    Tree[a-'A'].push_back(c);
  }
  preOrder(0 + 'A');
  cout << endl;
  InOrder(0+ 'A');
  cout << endl;
  postOrder(0+ 'A');
  return 0;

}