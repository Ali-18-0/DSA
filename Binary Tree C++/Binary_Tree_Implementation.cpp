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

// void levelOrderTraversalNode(node* root){
//     queue<node*> q;
//     q.push(root);
    

//     while(!q.empty()){
//         node* temp = q.front();
//         cout<<temp->data<<" ";
//         q.pop();

//         if(temp->left != NULL){
//             q.push(temp->left);
//         }
//         if(temp->right != NULL){
//             q.push(temp->right);
//         }

//     }
// }

void levelOrderTraversalNode2(node* root){
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
        } 
        else {
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void ReverselevelOrderTraversalNode(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        } 
        else {
            // cout<<temp->data<<" ";
            if(temp->right != NULL){
                q.push(temp->right);
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
        }
    }   s.pop();
        while (!s.empty()) {
        node* temp = s.top();
        s.pop();

        if (temp == NULL ) {
            cout << endl;
        } else {
            cout << temp->data << " ";
        }
    }
}
/***********************************************************************/
/* [LNR  = LEFT NODE(PRINT) RIGHT]  Recursive */
void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
// Iterative

void inOrder2(node* root){
    if(root == NULL){
        return;
    }
    stack<node*> s;
    stack<bool> b;
    s.push(root);
    b.push(0);
    while(!s.empty()){
        node* temp = s.top();
        bool flag = b.top();
        s.pop();
        b.pop();
        if(!flag){
            if(temp->right){
                s.push(temp->right);
                b.push(0);
            }
            s.push(temp);
            b.push(1);
            if(temp->left){
                s.push(temp->left);
                b.push(0);
            }
        } else {
            cout<<temp->data<<" ";

        }
    }
}
/***********************************************************************/
/* [NLR  = NODE(PRINT) LEFT RIGHT]  Recursive */

void PreOrder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// Iterative

void PreOrder2(node* root){
    if(root == NULL){
        return;
    }
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        cout<<temp->data<<" ";

        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}
/***********************************************************************/
/* [NLR  = NODE(PRINT) LEFT RIGHT]  Recursive */

void PostOrder(node* root){
    if(root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
// Iterative
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
/***********************************************************************/
// Leaf Node Count
int LeafCount(node* root){
    if(root == NULL){
        cout<<"Tree is Empty\n";
        return -1;
    }
    int count = 0;
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

/***********************************************************************/

int main(){

    node* root = NULL;

    root = buildtree(root);
    cout<<"Level Order Traversal : \n";
    levelOrderTraversalNode2(root);
    cout<<endl;
    cout<<"Reverse Level Order Traversal : \n";
    ReverselevelOrderTraversalNode(root);
    cout<<endl;
    cout<<"InOrder Traversal Recursively : ";
    inOrder(root);
    cout<<endl;
    cout<<"InOrder Traversal Iteratively : ";
    inOrder2(root);
    cout<<endl;
    cout<<"PreOrder Traversal Recursively : ";
    PreOrder(root);
    cout<<endl;
    cout<<"PreOrder Traversal Iteratively : ";
    PreOrder2(root);
    cout<<endl;
    cout<<"PostOrder Traversal Recursively : ";
    PostOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal Iteratively : ";
    PostOrder2(root);
    cout<<endl;
    cout<<"Leaf Node Count by Recursive : "<<LeafCount2(root);
    cout<<endl;
    cout<<"Leaf Node Count by Iterative : "<<LeafCount(root);
return 0;
}

// 1 2 6 -1 -1 5 -1 -1 3 7 -1 -1 9 -1 -1
