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

void inorder(node *root,vector<int> &v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
}

vector<int> mergeArray(vector<int> v1,vector<int> v2){
    vector<int> ans;
    int i = 0;
    int j = 0;

    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            ans.push_back(v1[i]);
            i++;
        } else {
            ans.push_back(v2[j]);
            j++;
        }
    }

    while(i<v1.size()){
        ans.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        ans.push_back(v2[j]);
        j++;
    }

    return ans;
}

node* sorted_list_to_BST(vector<int> v,int s,int e){
    if(s>e){
        return NULL;
    }

        int mid = (s+e)/2;
        node* root = new node(v[mid]);
        root->left = sorted_list_to_BST(v,s,mid-1);
        root->right = sorted_list_to_BST(v,mid+1,e);

        return root;
}

node* Merge2SortedBST(node* root1,node* root2){
    vector<int> v1;
    vector<int> v2;
    inorder(root1,v1);
    inorder(root2,v2);

    vector<int> mergeArr;

    mergeArr = mergeArray(v1,v2);
    int s = 0;
    int e = mergeArr.size()-1;
    
    return sorted_list_to_BST(mergeArr,s,e);
}

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

int main(){
    node* root1 = NULL;
    node* root2 = NULL;

    BuildBinarySearchTree(root1);
    BuildBinarySearchTree(root1);
    node* root = Merge2SortedBST(root1,root2);
    levelOrderTraversalNode2(root);


    

return 0;
}