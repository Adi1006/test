#include<bits/stdc++.h>
using namespace std;


// //creating a tree and travesal


 struct Node
 {
     int data;
     struct Node* left;
     struct Node* right;
       Node(int val){
         data=val;
         left=NULL;
         right=NULL;
       }
 };

 
// void preorder(struct Node* root){
//     if(root==NULL){
//         return ;
//     }
//   cout<<root->data<<" ";
//   preorder(root->left);
//   preorder(root->right);
// }

// void inorder(struct Node* root){
// if(root==NULL){
//     return;
// }
//  inorder(root->left);
//  cout<<root->data<<" ";
//  inorder(root->right);
// }
 
// void postorder(struct Node* root ){
//     if(root==NULL){
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     cout<<root->data<<" ";
// }

//  int main()
//  {
//      struct Node* root=new Node(1);
//      root->left=new Node(2);
//      root->right=new Node(3);
//       root->left->left=new Node(4);
//        root->left->right=new Node(5);
//      root->right->left=new Node(6);
//      root->right->right=new Node(7);
//    preorder(root);
//    cout<<endl;
//      inorder(root);
//      cout<<endl;
//      postorder(root);
//      return 0;
//  }
 


 //creating a tree with preorder and inordeer
// int search(int inorder[],int start,int end,int curr){
//    for (int i = start; i <= end; i++)
//    {
//        if(inorder[i]==curr){
//            return i;
//        }
//    }
//    return -1;
//  }
// Node* buildTree(int preorder[],int inorder[],int start,int end){
//         static int index=0;
//         if(start>end){
//             return NULL;
//         }
//         int curr=preorder[index];
//         index++;
//         Node* node=new Node(curr); 
//         if(start==end){
//             return node;
//         }
//         int pos=search(inorder,start,end,curr);
//         node->left=buildTree(preorder,inorder,start,pos-1);
//         node->right=buildTree(preorder,inorder,pos+1,end);
//         return node;
//              }

// void inoderPrint( Node* root){
//     if(root==NULL){
//         return;
//     }
//     inoderPrint(root->left);
//      cout<<root->data<<" ";
//      inoderPrint(root->right); 
// }
//  int main()
//  {
//     int preorder[]={1,2,4,3,5};
//     int inorder[]={4,2,1,5,3};
//      Node* root=buildTree(preorder,inorder,0,4);
//      inoderPrint(root);   
//      return 0;
//  }
 

 //creating a tree uing postoreder and inorder
 int search(int inorder[],int start,int end,int val){
     for (int i = start; i <=end; i++)
     {
         if(inorder[i]==val){
             return i;
         }
     }
     return -1;
 }
Node* buildTree(int postorder[],int inorder[],int start,int end){
static int index=4;
if(start>end){
    return NULL;
}
int val=postorder[index];
index--;
Node* curr=new Node(val);
if(start==end){
    return curr;
}
int pos=search(inorder,start,end,val);
curr->right=buildTree(postorder,inorder,pos+1,end);
 curr->left=buildTree(postorder,inorder,start,pos-1);

 return curr;
}
 
void inorderPrint(Node* root){
   if(root==NULL){
       return;
   }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

 int main()
 {
 int postorder[]={4,2,5,3,1};
int inorder[]={4,2,1,5,3};
Node*root=buildTree(postorder,inorder,0,4);
inorderPrint(root);

     return 0;
 }
 