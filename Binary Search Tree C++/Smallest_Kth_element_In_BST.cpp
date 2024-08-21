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


 int findK(node* root,int k,int &i){
        if(root == NULL){
            return -1;
        }
        int left = findK(root->left,k,i);
        if(left != -1){
            return left;
        }
        i++;
        if(i == k){
            return root->data;
        }
        
        return findK(root->right,k,i);
    }

    int KthSmallestElement(node *root, int K) {
        int i = 0;
        return findK(root,K,i);
    }

int main(){

return 0;
}