#include <iostream>
#include<vector>
using namespace std;
class Node{
 public: 
 int data;
 Node* left;
 Node* right;

 Node(int data){
  this->data=data;
  left=right=NULL;
 }
};

Node* insert(Node* root,int val){
 if(root==NULL){
   root=new Node(val);
   return root;
 }

 if(root->data>val){
  root->left=insert(root->left,val);
 }
 else{
  root->right=insert(root->right,val);
 }
 return root;
}

Node* buildTree(int *arr,int n){
   Node* root=NULL;
   for(int i=0;i<n;i++){
    root=insert(root,arr[i]);
   }
   return root;
}


void inorder(Node*root){
  if(root==NULL){
    return ;
  }

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

Node * getinordersuccesor(Node* root){
   while(root->left!=NULL){
       root=root->left;
   }
   return root;
}

Node* delNode(Node* root,int val){
   //base case
   if(root== NULL){
    return NULL;
   }

   if(root->data>val){
     root->left=delNode(root->left,val);
   }
   else if(root->data<val){
    root->right=delNode(root->right,val);
   }
   else{
    // if root-data==val
    //case 1 : -> leaf node 
    if(root->right==NULL && root->left==NULL){
        delete root;
        return NULL;
    }

    //case: 2; 1 child
    if(root->right==NULL || root->left==NULL){
        return root->left==NULL ? root->right: root->left;
    }

    //case :3 for 2 child;
    Node *IS = getinordersuccesor(root->right);
     //The in-order successor of a node X is the node with the smallest value greater than X->data.
    root->data=IS->data;
    root->right=delNode(root->right,IS->data);
   }
   return root;
}

void printInRange(Node* root,int start,int end){
  //base case 
  if(root==NULL){
    return ;
  }
  
  if(start<=root->data && root->data<=end){
    printInRange(root->left,start,end);
    cout<<root->data<<" ";
    printInRange(root->right,start,end);
  }

  else if(root->data<start){
     printInRange(root->right,start ,end);
  }
  else{
    printInRange(root->left,start,end);
  }

}

void printPath(vector<int> path){
  cout<<"path: "<<endl;
  for(int i=0;i<path.size();i++){
    cout<<path[i]<<" ";
  }
  cout<<endl;
}
void pathfinder(Node* root,vector<int>&path){
   //base case
   if(root==NULL){
    return;
   }

   path.push_back(root->data);

   if(root->left==NULL && root->right==NULL){
      printPath(path);
      path.pop_back();
      return;
   }

   pathfinder(root->left,path);
   pathfinder(root->right,path);
   path.pop_back();
}
//printing each path of tree
void printPathToleaf(Node*root){
  vector<int> path;
  pathfinder(root,path);
}
int main(){
  int arr[9]={8,5,3,1,4,6,10,11,14};
  Node* root=buildTree(arr,9);
  printPathToleaf(root);
  return 0;
}