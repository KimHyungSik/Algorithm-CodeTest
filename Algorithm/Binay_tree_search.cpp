#include <iostream>
#define MAX 15

using namespace std;

struct node{
  int data;
  node *leftPtr;
  node *rightPtr;
};

void preorder(node* root_node){
    if(root_node){
        cout << root_node->data << endl;
        preorder(root_node->leftPtr);
        preorder(root_node->rightPtr);
    }
}

void inorder(node* root_node){
    if(root_node){
        inorder(root_node->leftPtr);
        cout << root_node->data << endl;
        inorder(root_node->rightPtr);
    }
}

void postorder(node* root_node){
    if(root_node){
        postorder(root_node->leftPtr);
        postorder(root_node->rightPtr);
        cout << root_node->data << endl;
    }
}

int main(void){
  node Node[MAX];
  for(int i = 1; i <= MAX; i++){
    Node[i].data = i;
    Node[i].leftPtr = NULL;
    Node[i].rightPtr = NULL;
  }
  for(int i = 2; i < MAX; i++){
     if(i % 2 == 0){
       Node[i/2].leftPtr = &Node[i];
     }else{
       Node[i/2].rightPtr = &Node[i];
     }
  }
  preorder(&Node[1]);
  return 0;
}