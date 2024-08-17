#include<iostream>
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

node* buildTree(node* root){
    cout<<"Enter data of node : ";
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    } else {
        root = new node(d);
    }

    cout<<"Enter data for left node : \n";
    root->left = buildTree(root->left);
    cout<<"Enter data for right node : \n";
    root->right = buildTree(root->right);

    return root;
}

int height(node* root,bool &valid){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left,valid);
    int right = height(root->right,valid);

    if(abs(left - right) > 1){
        valid = false;
    }

    return max(left,right) +1;

}

void CheckHeightBalanace(node* root){
    if(root == NULL){
        cout<<"Tree is Empty\n";
        return;
    }
    bool valid = true;

    int check = height(root,valid);

    if(valid){
        cout<<"Tree is Balanced\n";
    } else {
        cout<<"Tree is not Balance\n";
    }

}

int main(){
    node* root = NULL;
    root = buildTree(root);

    CheckHeightBalanace(root);
return 0;
}