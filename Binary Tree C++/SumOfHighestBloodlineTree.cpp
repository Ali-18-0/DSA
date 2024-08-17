#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data for Node\n";
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    } else {
        root = new Node(data);
    }

    cout<<"Enter data for left Node\n";
    root->left = buildTree(root->left);
    cout<<"Enter data for right Node\n";
    root->right = buildTree(root->right);

    return root;
}

void check(Node* root,int sum,int len,int &Maxlen,int &Maxsum){
    if(root == NULL){
        return;
    }
    sum += root->data;
    
    if(root->left == NULL && root->right == NULL){
        if(len>Maxlen){
            Maxlen = len;
            Maxsum = sum;
        } else if(Maxlen == len){
            Maxsum = max(Maxsum,sum);
            return;
        }
    }
        check(root->left,sum,len+1,Maxlen,Maxsum);
        check(root->right,sum,len+1,Maxlen,Maxsum);
}
    
    int sumOfLongRootToLeafPath(Node *root){
        if(root == NULL){
            return 0;
        }
        int sum=0;
        int Maxsum = 0;
        int len = 0;
        int Maxlen = 0;
        
        check(root,sum,len,Maxlen,Maxsum);
        return Maxsum;
    }

 /*   void check(Node* root,int sum,int len,int &Maxlen,int &Maxsum){
    if(root == NULL){
        if(len>Maxlen){
            Maxlen = len;
            Maxsum = sum;
        } else if(Maxlen == len){
            Maxsum = max(Maxsum,sum);
    }
        return;
    }
    sum += root->data;

        check(root->left,sum,len+1,Maxlen,Maxsum);
        check(root->right,sum,len+1,Maxlen,Maxsum);
}
    
    int sumOfLongRootToLeafPath(Node *root){
        if(root == NULL){
            return 0;
        }
        int sum=0;
        int Maxsum = 0;
        int len = 0;
        int Maxlen = 0;
        
        check(root,sum,len,Maxlen,Maxsum);
        return Maxsum;
    } */
int main(){

return 0;
}