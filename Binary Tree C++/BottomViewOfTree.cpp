#include<iostream>
#include<vector>
#include<queue>
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


/******************************************************************************************/
// ITERATIVE
    void solve(Node* root,int a,int &l,int &r){
        if(root == NULL){
            return;
        }
        l = min(l,a);
        r = max(r,a);
        solve(root->left,a-1,l,r);
        solve(root->right,a+1,l,r);
    }

    vector<int> topView(Node *root)
    {
        vector<int> a;
        if(root == NULL){
            return a;
        }
        int l=0,r=0;
        solve(root,0,l,r);
        vector<int> ans(r-l+1);
        vector<bool> b(r-l+1,0);
        queue<Node*> q;
        queue<int> index;
        q.push(root);
        index.push(-1*l);
        while(!q.empty()){

            Node*temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            // if(!b[pos]){
                // b[pos] = 1;
                ans[pos] = temp->data;
            // }

            if(temp->left != NULL){
                q.push(temp->left);
                index.push(pos-1);
            }
            if(temp->right != NULL){
                q.push(temp->right);
                index.push(pos+1);
            }
        }
        
        return ans;
    }

/******************************************************************************************/

int main(){

return 0;
}