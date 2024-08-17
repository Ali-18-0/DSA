#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
    ~node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }

};

    void insertAtEnd(node* &head,int a){
        node* temp = new node(a);
        if(head == NULL){
            head = temp;
            return;
        }
        node* temp2 = head;
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;

    }

    bool deleteAtStart(node* &head){
        if(head == NULL){
            return false;
        }
        if(head->next ==NULL){
            delete head;
            head = NULL;
            return true;
        }
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return true;
    }

    int displayFirstElement(node* head){
        if(head == NULL){
            return -1;
        }
        return head->data;
    }

    int displayLastElement(node* head){
        if(head == NULL){
            return -1;
        }
        while(head->next != NULL){
            head = head->next;
        } 
        return head->data;
    }

    int sizeofLL(node* head){
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    void deleteLL(node* &head){
        if(head == NULL){
            return;
        } 
        node* temp = NULL;
        while(head!=NULL){
            temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        head = NULL;
    }

class Queue{
    node* head;

public:

    Queue(){
        head = NULL;
    }
    ~Queue(){
        if(head!=NULL){
            deleteLL(head);
        }
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        } 
        return false;
    }

    int front(){
        int a = displayFirstElement(head);
        if(a == -1){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return a;
    }

    int back(){
        int a = displayLastElement(head);
        if(a == -1){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return a;
    }

    void push(int a){
        insertAtEnd(head,a);

    }
    void pop(){
        if(!deleteAtStart(head)){
            cout<<"Queue is Empty\n";
        }
    }

    int size(){
        int a = sizeofLL(head);
        if(a == -1){
            cout<<"Queue is Empty\n";
            return -1;
        } 
        return a;
    }


};

int main(){


    Queue q;
    q.push(6);
    q.push(63);
    q.push(61);
    q.push(26);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<endl;

return 0;
}