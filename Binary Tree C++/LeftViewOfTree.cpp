#include<iostream>
#include<queue>
#include<vector>
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
/*Left View of Tree Iterative*/
vector<int> leftView(Node *root)
{
   queue<Node*> q;
   q.push(root);
   vector<int> v;
   int count=0;
   while(!q.empty()){
       count = q.size();
       v.push_back(q.front()->data);
       while(count!=0){
           Node* temp = q.front();
           q.pop();
           if(temp->left != NULL){
               q.push(temp->left);
           }
           if(temp->right != NULL){
               q.push(temp->right);
           }
           count--;
       }
   }
    return v;
}

/*Left View of tree Recursive*/
void solve(Node* root,int level,vector<int> &v){
    if(root == NULL){
        return;
    }
    if(level == v.size()){
        v.push_back(root->data);
    }
    solve(root->left,level+1,v);
    solve(root->right,level+1,v);
} 

vector<int> leftView(Node *root)
{
   int level = 0;
   vector<int> v;
   solve(root,level,v);
   return v;
}
int main(){

return 0;
}