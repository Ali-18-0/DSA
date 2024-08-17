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

class Queue_CIRCULAR{
    int sizee;
    int count;
    node* head;
    node* tail;

    public:
    Queue_CIRCULAR(int s){
        sizee = s;
        count = 0;
        head = NULL;
        tail = NULL;
    }
    Queue_CIRCULAR(){
        sizee = -1;
        count = 0;
        head = NULL;
        tail = NULL;
    }

    ~Queue_CIRCULAR(){
        if(!isEmpty()){
            node* temp = head;
            node* nex;
            do{
                nex = temp->next;
                delete temp;
                temp = nex;
            }while(temp!=head);
        }
        head = tail = NULL;
    }

    void push(int a){
        if(count == sizee){
            cout<<"Queue is Full\n";
            return;
        }
        node* temp = new node(a);
        if(head == NULL){
            head = tail = temp;
            tail->next = head;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
        count++;
    }

    void pop(){
        if(head == NULL){
            cout<<"Queue is Empty\n";
            return;
        }

        if(head == tail){
            delete head;
            head = tail = NULL;
        } else {
            node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        count--;
    }

    int fornt(){
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

    // Queue_CIRCULAR q;

    // q.push(5);
    // q.push(51);
    // q.push(512);
    // q.push(5123);
    // q.push(51234);

    // cout<<q.fornt()<<endl;
    // cout<<q.back()<<endl;
    // q.pop();
    // cout<<q.fornt()<<endl;
    // cout<<q.size()<<endl;
    // cout<<q.isEmpty()<<endl;


    Queue_CIRCULAR q(5);
    q.push(4);
    q.push(43);
    q.push(432);
    q.push(4321);
    q.push(43210);
     cout<<q.fornt()<<endl;
     cout<<q.back()<<endl;
     q.pop();
     cout<<q.fornt()<<endl;
     q.push(456);
    
return 0;
}