#include<iostream>
#include <climits>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* InsertintoBST(node* root,int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d>root->data){
        root->right = InsertintoBST(root->right,d);
    } else {
        root->left = InsertintoBST(root->left,d);
    }
    return root;
}

void BuildBinarySearchTree(node* &root){
    cout<<"Enter Data for node(enter -1 to stop) : ";
    int data;
    cin>>data;
    while(data != -1){
        root = InsertintoBST(root,data);
    cout<<"Enter Data for node(enter -1 to stop) : ";
        cin>>data;
    }
}

bool isTREEBST(node* root,int min,int max){
        if(root == NULL){
            return true;
        }
        if(root->data>min && root->data<max){
            bool left = isTREEBST(root->left,min,root->data);
            bool right = isTREEBST(root->right,root->data,max);
            return left && right;
        } else {
            return false;
        }
    }
    bool isBST(node* root) {
        return isTREEBST(root,INT_MIN,INT_MAX);
    }

int main(){

return 0;
}