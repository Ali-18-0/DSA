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
    cout<<"Enter Data for Node(enter -1 to stop) : ";
    int data;
    cin>>data;
    while(data != -1){
        root = InsertintoBST(root,data);
    cout<<"Enter Data for Node(enter -1 to stop) : ";
        cin>>data;
    }
}
/******************************************************************************************/
//Iterative WAY
int MIN_BST(node* root){
    if(root == NULL){
        return -1;
    }
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
/******************************************************************************************/
//Recursive WAY
int MIN_BST2(node* root){
    if(root == NULL){
            return -1;
        }
        
        if(root->left == NULL){
            return root->data;
        }
        return MIN_BST2(root->left);
}
/******************************************************************************************/

int main(){

return 0;
}