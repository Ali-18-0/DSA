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
/*******************************************************************************************/
node* find(node* root){
    while(root->left!=NULL){
    root = root->left;
    }
    return root;
}

node* find(node* root){
    while(root->right!=NULL){
    root = root->right;
    }
    return root;
}

void succe(node* root,int x,node* &suc,node* &pre){
    if(root == NULL){
        return ;
    }
    if(root->data == x){
        if(root->right){
            suc = find(root->right);
        }
        if(root->left){
            suc = find(root->left);
        }
    } else if(root->data<x){
        pre = root;
        succe(root->right,x,suc,pre);
    } else {
        suc = root;
        succe(root->left,x,suc,pre);
    }
}
    void inOrderSuccessor(node *root, node *x){
        node* suc = NULL;
        node* pre = NULL;
         succe(root,x->data,suc,pre);
         cout<<"Successor : "<<suc <<"Predecessor : "<<pre<<endl;
    }
/*******************************************************************************************/
// Easy Approach

void Find_Pre_Suc(node*root,node* k){
    int suc = -1;
    int pre = -1;
    node* temp = root;
    int Kth = k->data;
    while(temp->data != Kth || temp != NULL){

        if(Kth > temp->data){
            pre = temp->data;
            temp = temp->right;
        } else if(Kth < temp->data){
            suc = temp->data;
            temp = temp->left;
        }
    }

    //Suc
    node* RightTree = temp->right;
    while(RightTree != NULL){
        suc = RightTree->data;
        RightTree = RightTree->left;
    }

    //Pre
    node* LeftTree = temp->left;
    while(RightTree != NULL){
        suc = RightTree->data;
        RightTree = RightTree->right;
    }

    if(suc == -1){
        cout<<"No Successor of "<<Kth<<" in this Tree \n";
    } else {
        cout<<"Successor of "<<Kth<<" in this Tree is : "<<suc<<endl;
    }

    if(pre == -1){
        cout<<"No Predecessor of "<<Kth<<" in this Tree \n";
    } else {
        cout<<"Predecessor of "<<Kth<<" in this Tree is : "<<pre<<endl;
    }


}

int main(){

return 0;
}