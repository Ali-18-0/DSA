#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void buildTree(Node* &root){
    cout<<"Enter data for Node : \n";
    int data;
    cin>>data;
    if(data == -1){
        return;
    }
    Node* temp = new Node(data);
    root = temp;
    cout<<"Enter data for Left Node \n";
    buildTree(root->left);
    cout<<"Enter data for Right Node \n";
    buildTree(root->right);
        
}

    void solve(Node* root,int &c){
        if(root == NULL){
            return;
        }
        if(root->left != NULL && root->right != NULL){
            c++;
        } else if(root->left == NULL && root->right != NULL){
            c++;
        } else if(root->left != NULL && root->right == NULL){
            c++;
        }
        
        solve(root->left,c);
        solve(root->right,c);
    }
    
    int countNonLeafNodes(Node* root) {
        int count = 0;
        solve(root,count);
        return count;
    }
int main(){

return 0;
}