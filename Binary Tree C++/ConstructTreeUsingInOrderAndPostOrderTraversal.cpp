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

int find(int in[],int target,int s,int e){
        for(int i=s;i<=e;i++){
            if(in[i] == target){
                return i;
            }
        }
        return -1;
    }
    node* Tree(int in[],int post[],int start,int end,int index){
        
        if(start>end){
            return NULL;
        }
        
        node* root = new node(post[index]);
        int pos = find(in,post[index],start,end);
        root->right = Tree(in,post,pos+1,end,index-1);
        root->left = Tree(in,post,start,pos-1,index-(end-pos)-1);
        return root;
    }

    node *buildTree(int n, int in[], int post[]) {
        
        return Tree(in,post,0,n-1,n-1);
    }

int main(){

return 0;
}