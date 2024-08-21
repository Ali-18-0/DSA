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
/****************************************************************************/
//Deletion of Node in Tree

int findmin(node* root){
    if(root == NULL){
        return -1;
    }
    if(root->left != NULL){
        return findmin(root->left);
    }
    return root->data;
    
}
node *deleteNode(node *root, int X,bool &f) {
    if(root == NULL){
        return root;
    }
    if(root->data == X){
        f = true;
        
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        } else if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        } else if(root->left != NULL && root->right != NULL){
            int min =findmin(root->right);
            root->data = min;
            root->right = deleteNode(root->right,min,f);
        }
    } else if(X>root->data){
        root->right = deleteNode(root->right,X,f);
    } else {
        root->left = deleteNode(root->left,X,f);
    }
    return root;
}

node* DeletionOfNode(node* root,int x){
    bool check = false;
    root = deleteNode(root,x,check);
    if(check){
        cout<<"The Desired Node is deleted Successfully \n";
    } else {
        cout<<"The Desired is not deleted because it's not found in ths entire Tree \n";
    }
    return root;
}
/****************************************************************************/

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

int main(){

    node* root = NULL;
    BuildBinarySearchTree(root);
    levelOrderTraversal(root);
    root = DeletionOfNode(root,2);
    levelOrderTraversal(root);

return 0;
}