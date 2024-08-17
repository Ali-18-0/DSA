#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

class Queue{
    node* head;
    node* tail;
    int sizee;
    int count;

    public:
    Queue(int s){
        sizee = s;
        head = NULL;
        tail = NULL;
        count = 0;
    }
    Queue(){
        head = NULL;
        tail = NULL;
        sizee = -1;
        count = 0;
    }

    ~Queue(){
        while(head!=NULL){
            node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }

    void push(int d){
        if(count==sizee){
            cout<<"Queue is FULL\n";
            return;
        } 
        node* temp = new node(d);
        if(head == NULL){
            head = tail = temp;
        } else {
        tail->next = temp;
        tail = temp;
        }
        
        count++;
    }

    void pop(){
        if(head == NULL){
            cout<<"Queue is empty\n";
            return;
        }

        node* temp = head;
        head = head->next;

        if(head == NULL){
            tail = NULL;
        }

        delete temp;
        count--;
    }

    int front(){
        if(head == NULL){
            cout<<"Queue is Empty\n";
            return -1;
        }

        return head->data;
    }

    int back(){
        if(head == NULL){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return tail->data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return head == NULL;
    }

};

int main(){

    // Queue q;
    // q.push(5);
    // q.push(19);
    // q.push(23);
    // q.push(111);


    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;
    // cout<<q.size()<<endl;
    // cout<<q.isEmpty()<<endl;
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();


    Queue q(5);
    q.push(5);
    q.push(3);
    q.push(1);
    q.push(8);
    q.push(5123);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    q.push(88);
    cout<<q.front();
return 0;
}