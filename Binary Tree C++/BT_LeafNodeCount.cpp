#include<iostream>
#include<queue>
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

node* buildTree(node* root){
    cout<<"Enter node data \n";
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    } else {
        root = new node(data);
    }

    cout<<"Insering in Left Node ";
    root->left = buildTree(root->left);
    cout<<"Insering in Right Node ";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

int LeafCount(node* root){
    if(root == NULL){
        cout<<"Tree is Empty\n";
        return -1;
    }
    int count;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(!(temp->left)){
            if(!(temp->right)){
                count++;
            }
        } else {
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return count;
}
void CountSolve(node* root,int &count){
    if(root == NULL){
        return;
    }
    CountSolve(root->left,count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    CountSolve(root->right,count);
}
int LeafCount2(node* root){
    int count = 0;
    CountSolve(root,count);
    return count;
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    cout<<"\n Total number of Leaf Nodes are Iterative : "<<LeafCount(root)<<endl;
    cout<<"\n Total number of Leaf Nodes are Iterative : "<<LeafCount2(root)<<endl;

return 0;
}