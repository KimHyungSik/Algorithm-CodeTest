#include <iostream>
#include <vector>

using namespace std;
int N;
const int MAX = 26;
int parent[MAX];
vector<vector<char>> Tree;

//���� ��ȸ 
void preOrder(char root){
  if(root == '.')
    return;
  char left = Tree[root-'A'][0];
  char right = Tree[root-'A'][1];
  printf("%c",root);
  preOrder(left);
  preOrder(right);
}

//���� ��ȸ
void InOrder(char root){
  if(root == '.')
    return;
  char left = Tree[root - 'A'][0];
  char right = Tree[root - 'A'][1];

  InOrder(left);
  printf("%c", root);
  InOrder(right);
}

//���� ��ȸ
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
  Tree = vector<vector<char>>(N, vector<char>());//�� ũ�� N�� �ڽķ�Ʈ �� �� vector ����
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