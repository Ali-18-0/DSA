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

bool isIdentical(node *r1, node *r2)
    {
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        if((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL)){
            return false;
        }
        
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        
        bool checkdata = r1->data == r2->data;
        
        if(left && right && checkdata){
            return true;
        }
        return false;
        
    }

int main(){

    node* r1 = NULL;
    node* r2 = NULL;
    
    r1 = buildTree(r1);
    cout<<endl;
    r2 = buildTree(r2);

    if(isIdentical(r1,r2)){
        cout<<"YES";
    } else {
        cout<<"NO";
    }

return 0;
}