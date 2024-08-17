#include<iostream>
using namespace std;

class Bnode{
    public:
    bool b;
    Bnode* next;

    Bnode(bool t){
        b = t;
        next = NULL;
    }

};

class Bstack{
    Bnode* head;
    
    public:
        Bstack(){
            head = NULL;
        }
        ~Bstack(){
            while(!isEmpty()){
                pop();
            }
        }

    bool isEmpty(){
        return head == NULL;
    }
    
    bool top(){
        if(isEmpty()){
            return NULL;
        }
        return head->b;   
    }
    void push(bool b){
        Bnode* temp =  new Bnode(b);

        temp->next = head;
        head = temp;
    }
    void pop(){
        if(isEmpty()){
            return;
        }
        
        Bnode* temp = head;
        head = head->next;
        delete temp;
    }
};


// class Bqueue{

//     Bnode* head;
//     Bnode* tail;
//     public:
//     Bqueue(){
//         head = NULL;
//         tail = NULL;
//     }
//     ~Bqueue(){
//         while(!isEmpty()){
//             pop();
//         }
//     }

//     bool front(){
//         if(head == NULL){
//             return NULL;
//         }
//         return head->b;
//     }
//     bool back(){
//         if(head == NULL){
//             return NULL;
//         }
//         return tail->b;
//     }
//     bool isEmpty(){
//         return head == NULL;
//     }

//     void push(bool b){
//         Bnode* temp = new Bnode(b);
        
//         if(isEmpty()){
//             head = tail = temp;
//         } else{
//             tail->next = temp;
//             tail = temp;
//         }
//     }

//     void pop(){
//         if(isEmpty()){
//             return;
//         }
//         if(head == tail){
//             delete head;
//             head = tail = NULL;
//         } else {
//             Bnode* temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }
// };

class node_BT{
    public:
        int data;
        node_BT* left;
        node_BT* right;

        node_BT(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~node_BT(){
            if(left != NULL){
                delete left;
                left = NULL;
            }
            if(right != NULL){
                delete right;
                right = NULL;
            }
        }
};

class node{
    public:
        node_BT* bt;
        node* next;
        node(node_BT* bt){
            this->bt = bt;
            next = NULL;
        }
};

class queue{
    node* head;
    node* tail;
    public:
    queue(){
        head = NULL;
        tail = NULL;
    }
    ~queue(){
        while(!isEmpty()){
            pop();
        }
    }

    node_BT* front(){
        if(head == NULL){
            return NULL;
        }
        return head->bt;
    }
    node_BT* back(){
        if(head == NULL){
            return NULL;
        }
        return tail->bt;
    }
    bool isEmpty(){
        return head == NULL;
    }

    void push(node_BT* t){
        node* temp = new node(t);
        
        if(isEmpty()){
            head = tail = temp;
        } else{
            tail->next = temp;
            tail = temp;
        }
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        } else {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class stack{
    node* head;
    
    public:
        stack(){
            head = NULL;
        }
        ~stack(){
            while(!isEmpty()){
                pop();
            }
        }

    bool isEmpty(){
        return head == NULL;
    }
    
    node_BT* top(){
        if(isEmpty()){
            return NULL;
        }
        return head->bt;   
    }
    void push(node_BT* t){
        node* temp =  new node(t);

        temp->next = head;
        head = temp;
    }
    void pop(){
        if(isEmpty()){
            return;
        }
        
        node* temp = head;
        head = head->next;
        delete temp;
    }
};



node_BT* buildTree(node_BT* root){
    cout<<"Enter your data Node\n";
    int data;
    cin>> data;
    if(data == -1){
        return NULL;
    } else {
        root = new node_BT(data);
    }

    cout<<"Enter data for left node_BT\n";
    root->left = buildTree(root->left);
    cout<<"Enter data for right node_BT\n";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversalStraight(node_BT* root){
    if(root == NULL){
        return;
    }

    queue q;
    q.push(root);

    while(!q.isEmpty()){
        node_BT* temp = q.front();
        cout<<q.front()->data<<" ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(node_BT* root){
    if(root == NULL){
        return;
    }
    queue q;
    q.push(root);
    q.push(NULL);

    while(!q.isEmpty()){
        node_BT* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.isEmpty()){
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

void ReverselevelOrderTraversal(node_BT* root){
    if(root == NULL){
        return;
    }
    queue q;
    stack s;
    q.push(root);
    q.push(NULL);

    while(!q.isEmpty()){
        node_BT* temp = q.front();
        s.push(temp);
        q.pop();

        if(temp == NULL){
            if(!q.isEmpty()){
                q.push(NULL);
            }
        } else {
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }

        s.pop();
        while(!s.isEmpty()){
            node_BT* test = s.top();
            s.pop();
            if(test == NULL){
                cout<<endl;
            } else {
                cout<<test->data<<" ";
            }
        }
}

void inOrder_RE(node_BT* root){
    if(root == NULL){
        return;
    }
    inOrder_RE(root->left);
    cout<<root->data<<" ";
    inOrder_RE(root->right);
}

void inOrder_IT(node_BT* root){
    if(root == NULL){
        return;
    }
    stack s;
    Bstack b;
    s.push(root);
    b.push(0);

    while(!s.isEmpty()){
        node_BT* temp = s.top();
        bool check = b.top();
        s.pop();
        b.pop();

        if(!check){
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

void preOrder_RE(node_BT* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder_RE(root->left);
    preOrder_RE(root->right);
}

void preOrder_IT(node_BT* root){
    if(root  == NULL){
        return;
    }
    stack s;
    s.push(root);

    while(!s.isEmpty()){
        node_BT* temp = s.top();
        cout<<temp->data<<" ";
        s.pop();

        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

void postOrder_RE(node_BT* root){
    if(root == NULL){
        return;
    }
    postOrder_RE(root->left);
    postOrder_RE(root->right);
    cout<<root->data<<" ";
}

void postOrder_IT(node_BT* root){
    if(root == NULL){
        return;
    }

    stack s1;
    stack s2;
    s1.push(root);

    while(!s1.isEmpty()){
        node_BT* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }

    while(!s2.isEmpty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}


int main(){

    node_BT* root = NULL;
    root = buildTree(root);
    cout<<"Level Order Traversal Straight : ";
    levelOrderTraversalStraight(root);
    cout<<endl;
    cout<<"Level Order Traversal Recursive : ";
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Level Order Traversal Iterative : ";
    ReverselevelOrderTraversal(root);
    cout<<endl;
    cout<<"In Order Traversal Recursive : ";
    inOrder_RE(root);
    cout<<endl;
    cout<<"In Order Traversal Iterative : ";
    inOrder_IT(root);
    cout<<endl;
    cout<<"Pre Order Traversal Recursive : ";
    preOrder_RE(root);
    cout<<endl;
    cout<<"Pre Order Traversal Iterative : ";
    preOrder_IT(root);
    cout<<endl;
    cout<<"post Order Traversal Recursive : ";
    postOrder_RE(root);
    cout<<endl;
    cout<<"post Order Traversal Iterative : ";
    postOrder_IT(root);

return 0;
}
//1 2 6 -1 -1 5 -1 -1 3 7 -1 -1 9 -1 -1