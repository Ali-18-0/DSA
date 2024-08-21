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
    cout<<"Enter Data for Node(enter -1 to stop) : ";
    int data;
    cin>>data;
    while(data != -1){
        root = InsertintoBST(root,data);
    cout<<"Enter Data for Node(enter -1 to stop) : ";
        cin>>data;
    }
}
/**************************************************************************/
// Iterative WAY:

void check(node* root,int x,bool &flag){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        flag=true;
    } else if(x>root->data){
        check(root->right,x,flag);
    } else {
        check(root->left,x,flag);
    }
}

bool search(node* root, int x) {
    bool flag = false;
    check(root,x,flag);
    return flag;
    }
/**************************************************************************/
// Recursive WAY

bool search2(node* root, int x) {
   
    if(root == NULL){
        return false;
    }
    
    node* temp = root;
    while(temp!=NULL){
        if(temp == NULL){
            return false;
        }
        if(temp->data == x){
            return true;
        } else if(x>temp->data){
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return false;
}


/**************************************************************************/
int main(){

    node* root = NULL;
    BuildBinarySearchTree(root);
    if(search(root,5)){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }


    if(search2(root,5)){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }

return 0;
}