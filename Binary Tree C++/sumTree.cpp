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


/* int checkSum(node* root,bool &valid){
        if(root == NULL){
            return -1;
        }
        
        int left = checkSum(root->left,valid);
        int right = checkSum(root->right,valid);
        if(left == -1 && right == -1){
            return root->data;
        }
        int newd = 0;
        if(left == -1 && right != -1){
            newd= right;
        } else if(right == -1 && left != -1){
            newd= left;
        } else {
            newd= newd + left+right;
        }
        if(root->data != newd){
            valid = false;
        }
        return newd+root->data;
    }

    bool isSumTree(node* root) {
        
        bool valid = true;
        int check = checkSum(root,valid);
        return valid;
    }
*/
int checkSum(node* root,bool &valid){
        if(root == NULL){
            return 0;
        }
        
        if(!root->left && !root->right){
            return root->data;
        }
        int left = checkSum(root->left,valid);
        int right = checkSum(root->right,valid);
        
        
        if(root->data != left + right){
            valid = false;
        }
        return right + left + root->data;
    }
    bool isSumTree(node* root) {
        
        bool valid = true;
        int check = checkSum(root,valid);
        return valid;
    }

int main(){

return 0;
}