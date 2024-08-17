#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
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

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right) +1;
}

int Diameter(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return left+right+1;
}
int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<Diameter(root)<<endl;

return 0;
}