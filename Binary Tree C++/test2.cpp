#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data for Node\n";
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    } else {
        root = new Node(data);
    }

    cout<<"Enter data for left Node\n";
    root->left = buildTree(root->left);
    cout<<"Enter data for right Node\n";
    root->right = buildTree(root->right);

    return root;
}

void printLeft(Node* root,vector<int> &v){
    if(root == NULL || root->left == NULL){
        return;
    }
    v.push_back(root->data);
    printLeft(root->left,v);
}

void printLeaf(Node* root,vector<int> &v){
    if(root == NULL){
        return;
    }
    printLeaf(root->left,v);
    printLeaf(root->right,v);
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
    }
}

void printRight(Node* root,stack<Node*> &s){
    if(root == NULL || root->right == NULL){
        return;
    }
    s.push(root);
    printRight(root->right,s);
}

vector<int> BoundaryTraversal(Node* root){
    vector<int> v;
    if(root == NULL){
        return v;
    }
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
        return v;
    }
    if(root->left != NULL){
    printLeft(root,v);
    } else {
        v.push_back(root->data);
    }
    printLeaf(root,v);
    stack<Node*> s;
    if(root->right->right->right != NULL){
        printRight(root->right,s);
    } else if(root->right->right != NULL) {
        v.push_back(root->right->data);
    }
    while(!s.empty()){
        v.push_back(s.top()->data);
        s.pop();
    }
    return v;
   
}
int main(){

    Node* root = NULL;
    root = buildTree(root);
    vector<int> test;
    test = BoundaryTraversal(root);
    // printLeft(root,test);
    // printLeaf(root,test);
    // stack<Node*> s;
    // printRight(root,s);
    // while(!s.empty()){
    //     cout<<s.top()->data<<" ";
    //     s.pop();
    // }
    while(!test.empty()){
        cout<<test.back()<<" ";
        test.pop_back();
    }

return 0;
}