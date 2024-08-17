#include<iostream>
#include<stack>
#include<vector>
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
    cout<<"Enter data for node\n";
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    } else {
        root = new node(data);
    }

    cout<<"Enter data for left node\n";
    root->left = buildTree(root->left);
    cout<<"Enter data for right node\n";
    root->right = buildTree(root->right);

    return root;
}

void printLeft(node* root){
    if(root == NULL || root->left == NULL){
        return;
    }
    cout<<root->data<<" ";
    printLeft(root->left);
}

void printLeaf(node* root){
    if(root == NULL){
        return;
    }
    printLeaf(root->left);
    printLeaf(root->right);
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
}

void printRight(node* root,stack<node*> &s){
    if(root == NULL || root->right == NULL){
        return;
    }
    s.push(root);
    printRight(root->right,s);
}

void BoundaryTraversal(node* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
    printLeft(root);
    } else {
        cout<<root->data<<" ";
    }
    printLeaf(root);
    stack<node*> s;
    if(root->right->right->right !=NULL){
        printRight(root->right,s);
    } else if(root->right->right) {
        cout<<root->right->data<<" ";
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
   
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    BoundaryTraversal(root);

    vector<int> v;
    
    

return 0;
}