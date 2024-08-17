#include<iostream>
#include<queue>
#include<vector>
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

void LevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
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

void TreeLineAxis(Node* root,int a,int &l,int &r){
    if(root == NULL){
        return;
    }
    l = min(a,l);
    r = max(a,r);

    TreeLineAxis(root->left,a-1,l,r);
    TreeLineAxis(root->right,a+1,l,r);
}

vector<int> VerticalOrderTraversal(Node* root){
    vector<int> v;
    if(root == NULL){
        return v;
    }
    int l=0,r=0;
    TreeLineAxis(root,0,l,r);
    vector<vector<int>> ans(r-l+1);
    queue<Node*> q;
    queue<int> index;
    q.push(root);
    index.push(-l);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        ans[pos].push_back(temp->data);
        
        if(temp->left != NULL){
            q.push(temp->left);
            index.push(pos-1);
        }
        if(temp->right != NULL){
            q.push(temp->right);
            index.push(pos+1);
        }
    }

    vector<int> answer;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            answer.push_back(ans[i][j]);
        }
    }
    return answer;

}
int main(){

    // Node* root = NULL;
    // Node a(5);
    // cout<<a.data;
    // cout<<a.left;
    // cout<<a.right;
    // Node b(6);
    // a.left = &b;
    // cout<<endl<<a.left->data<<endl;
    // int* arr = new int(5);
    // cout<<*arr<<endl;
    // int sd = 6;
    // int*w = &sd;
    // cout<<*w<<endl;;
    // Node* test = new Node(5);
    // cout<<test<<endl;
    // cout<<&test<<endl;
    // buildTree(root);
    // LevelOrderTraversal(root);

    Node* root = NULL;
    buildTree(root);
    vector<int> ans;
    ans =VerticalOrderTraversal(root);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    

return 0;
}