#include<iostream>
using namespace std;
class Node {
  public:
  int val;
  Node *left;
  Node *right;
  Node(int data){
    this->val = data;
    left = NULL;
    right = NULL;
  }
};

Node* buildTree(){
  int node;
  cin >> node;
  if(node==-1){
    return NULL;
  }

  Node *root = new Node(node);
  root->left = buildTree();
  root->right = buildTree();
  return root;
}

void preorder(Node* root){
    if(root==NULL){
      return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
  Node *root = buildTree();
  preorder(root);
  return 0;
}