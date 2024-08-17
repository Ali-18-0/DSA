#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void buildTree(node* &root){
    cout<<"Enter data for node : \n";
    int data;
    cin>>data;
    if(data == -1){
        return;
    }
    node* temp = new node(data);
    root = temp;
    cout<<"Enter data for Left node \n";
    buildTree(root->left);
    cout<<"Enter data for Right node \n";
    buildTree(root->right);
        
}

void K_Path(node* root,int &count,vector<int> a,int k){
    if(root == NULL){
        return;
    }
    a.push_back(root->data);

    K_Path(root->left,count,a,k);
    K_Path(root->right,count,a,k);

    int sum = 0;
    int size = a.size();
    for(int i=size-1;i>=0;i--){
        sum+=a[i];
        if(sum == k){
            count++;
        }
    }
}

int Check(node* root,int key){
    int count = 0;
    vector<int> a;

    K_Path(root,count,a,key);
    return count;
}

int main(){

    node* root = NULL;
    buildTree(root);
    cout<<"Total number of K is "<<Check(root,3);
return 0;
}