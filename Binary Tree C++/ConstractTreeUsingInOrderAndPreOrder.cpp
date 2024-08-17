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
    node* Tree(int in[],int pre[],int start,int end,int index){
        
        if(start>end){
            return NULL;
        }
        
        node* root = new node(pre[index]);
        int pos = find(in,pre[index],start,end);
        root->left = Tree(in,pre,start,pos-1,index+1);
        root->right = Tree(in,pre,pos+1,end,index+(pos-start)+1);
        return root;
    }
    node* builingTree(int in[],int pre[], int n){

       return Tree(in,pre,0,n-1,0);
    }


void levelOrderTraversalNode(node* root){
    queue<node*> q;
    q.push(root);
    

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }

    }
}

int main(){
    int in[] = {2,1,3};
    int pre[] = {1,2,3};
    node* root = Tree(in,pre,0,3,0);
    levelOrderTraversalNode(root);
    


return 0;
}