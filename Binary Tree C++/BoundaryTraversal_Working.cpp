#include<iostream>
#include<vector>
#include<stack>
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

void getLeft(node* root,vector<int> &v){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    v.push_back(root->data);
    if(root->left != NULL){
        getLeft(root->left,v);
    } else {
        getLeft(root->right,v);
    }
}
void getLeaf(node* root,vector<int> &v){
    if(root == NULL){
        return;
    }
    getLeaf(root->left,v);
    getLeaf(root->right,v);
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
    }
}

void getRight(node* root,stack<node*> &s){
    if(root == NULL || (root->left==NULL && root->right == NULL)){
        return;
    }
    s.push(root);
    if(root->right != NULL){
        getRight(root->right,s);
    } else {
        getRight(root->left,s);
    }
}

vector<int> boundary(node* root){
    vector<int> v;
    if(root == NULL){
        return v;
    }
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
        return v;
    }
    v.push_back(root->data);
    getLeft(root->left,v);
    getLeaf(root,v);
    stack<node*> s;
    getRight(root->right,s);
    while(!s.empty()){
        v.push_back(s.top()->data);
        s.pop();
    }

    return v;

}

int main(){

    node* root = NULL;
    root = buildTree(root);
    vector<int> v = boundary(root);
    while(!v.empty()){
        cout<<v.back()<<" ";
        v.pop_back();
    }


return 0;
}