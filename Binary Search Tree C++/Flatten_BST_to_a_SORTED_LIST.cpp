#include<iostream>
#include<vector>
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

void inorder(node *root,vector<int> &v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
}

node* SortedTree(node* root){
    
    vector<int> v;
    inorder(root,v);
    
    node* newroot = new node(v[0]);
    node* curr = newroot;

    for(int i=1;i<v.size();i++){
        node* temp = new node(v[i]);
        curr->right = temp;
        curr = temp;
    }

    return newroot;

}
void sortedview(node* root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->right;
    }
}

int main(){

    node* root = NULL;
    BuildBinarySearchTree(root);
    cout<<endl;
    levelOrderTraversalNode(root);
    cout<<endl;
    node* newroot = SortedTree(root);
    cout<<endl;
    sortedview(newroot);
    



return 0;
}