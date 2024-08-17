#include<iostream>
#include<queue>
#include<stack>
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
        ~node(){
            if(left!= NULL){
                delete left;
                left = NULL;
            }
            if(right != NULL){
                delete right;
                right = NULL; 
            }
        }
};


node* buildtree(node* root){
    cout<<"Enter Data \n";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    } else {
    root = new node(data);
    }

    cout<<"Enter data for inserting in left\n";
    root->left = buildtree(root->left);
    cout<<"Enter data for inserting in right\n";
    root->right = buildtree(root->right);

    return root;

}

void PostOrder2(node* root){
    if(root == NULL){
        return;
    }

    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);

    while(!s1.empty()){
        node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
        
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

int main(){

    node* root = buildtree(root);
    PostOrder2(root);

return 0;
}