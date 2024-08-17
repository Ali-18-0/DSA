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

int sumTreeNodes(node* root){
    if(root == NULL){
        return 0;
    }
    int left = sumTreeNodes(root->left);
    int right = sumTreeNodes(root->right);
    return left + right + root->data;
}
int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"\nSum of Tree Nodes : "<<sumTreeNodes(root);

return 0;
}