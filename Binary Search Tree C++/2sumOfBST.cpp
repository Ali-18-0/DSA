#include<iostream>
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

void inorder(node *root,vector<int> &v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

    // root : the root node of the given BST
    // target : the target sum
    int isPairPresent(node *root, int target)
    {
    vector<int> v;
    inorder(root,v);
    int a = 0,b = v.size()-1;
    int flag = 0;
    while(a<b){
        int check = v[a]+v[b];
        if(check == target){
            flag = 1;
            break;
        }
        if(target > check){
            a++;
        } else {
            b--;
        }
        
    }
    return flag;
    }

int main(){

    
return 0;
}