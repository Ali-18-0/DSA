#include<iostream>
#include<queue>
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

void ZicZacTraversal(node* root){
    if(root == NULL){
        cout<<"Tree is Empty\n";
        return;
    }

    queue<node*> q;
    q.push(root);
    bool check = true;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(check){
            
        }
    }
}

int main(){

return 0;
}