#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~node(){
        if(this->next !=NULL){
            delete next;
            next = NULL;
        }
    }
};

void insertAtEnd(node* &head,int d){
    node* temp = new node(d);
    if(head == NULL){
        head = temp;
        return;
    }
    node* tempo = head;
    while(tempo->next!=NULL){
        tempo = tempo->next;
    }
    tempo->next = temp;
}

bool deleteAtEnd(node* &head){
    if(head == NULL){
        return false;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return true;
    }
    node* curr = head;
    node* pre = NULL;
    while(curr->next!=NULL){
        pre = curr;
        curr = curr->next;
    }
    pre->next = NULL;
    delete curr;

    return true;
}
int displayEndNode(node* head){
    if(head == NULL){
            return -1;
    } 
    while(head->next!=NULL){
        head = head->next;
    }
    return head->data;
    
    
}

int sizeofll(node* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}

class Stack_LL{
    public:
    node* list;

    Stack_LL(){
        list = NULL;
    }

    ~Stack_LL(){
        
        node* temp = list;
        while(list!=NULL){
            list = list->next;
            temp->next = NULL;
            delete temp;
        }
        temp = list;
        list = NULL;
        cout<<"\nDestructor Called, Stack deleted\n";
        
    }

    void push(int d){
        insertAtEnd(list,d);
    }

    void pop(){
        if(!(deleteAtEnd(list))){
            cout<<"Stack Underflow";
        }

    }

    int size(){
        return sizeofll(list);

    }

    int peek(){
        if(displayEndNode(list) == -1){
        cout<<"\nStack Underflow\n";
        return -1;
        }
        return displayEndNode(list);
    }

    bool isEmpty(){
        if(list == NULL){
            return true;
        } else {
            return false;
        }
    }
};

int main(){

    Stack_LL st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    // cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;

    if(st.isEmpty()){
        cout<<"\nTrue"<<endl;
    } else {
        cout<<"\nFalse"<<endl;
    }

    cout<<st.size();
return 0;
}