#include<iostream>
using namespace std;

class Queue_Doubly{
    int* arr;
    int sizee;
    int frontt;
    int rear;

    public:
    Queue_Doubly(int s){
     sizee = s;
     arr = new int[s];
    frontt = -1;   
    rear = -1;   
    }
    ~Queue_Doubly(){
        delete[] arr;
    }

    bool isEmpty(){
        if(frontt == -1 && rear == -1){
            return true;
        } else {
            return false;
        }
    }

    void push_front(int a){
        if((frontt==0) && (rear==sizee-1) || rear == (frontt-1)%(sizee-1)){
            cout<<"Queue is Full\n";
            return;
        }
        if(isEmpty()){
            frontt = rear = 0;
        }else if(frontt == 0 && rear!=sizee-1){
            frontt = sizee-1;
        } else {
            frontt--;
        }
        arr[frontt] = a;
    }

    void push_back(int a){
        if((frontt==0) && (rear==sizee-1) || rear == (frontt-1)%(sizee-1)){
            cout<<"Queue is Full\n";
            return;
        }
        if(isEmpty()) {
            frontt = rear = 0;
        } else if(rear == sizee-1 && frontt != 0){
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = a;
    }

    void pop_front(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        } 
        arr[frontt] = -1;
        if(frontt == rear){
            rear = frontt = -1;
        } else if(frontt == sizee-1){
            frontt = 0;
        } else {
            frontt++;
        }
    }

    void pop_back(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        } 
        arr[rear] = -1;
        if(frontt == rear){
            frontt = rear = -1;
        } else if(rear == 0){
            rear = sizee-1;
        } else {
            rear--;
        }
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return -1;
        } 
        return arr[frontt];
    }
    int back(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return -1;
        } 
        return arr[rear];
    }

    int size(){
        if(frontt<=rear){
            return (rear-frontt)+1;
        }
        return (rear+1) + (sizee-frontt);
    }
    
};


int main(){

    Queue_Doubly q(5);

    q.push_front(2);
    cout<<q.front()<<endl;
    q.push_back(5);
    cout<<q.back()<<endl;
    q.push_back(3);
    cout<<q.back()<<endl;
    q.push_back(9);
    cout<<q.back()<<endl;
    q.push_back(12);
    cout<<q.back()<<endl;
    // q.push_front(123);
    // q.push_back(21);
    q.pop_front();
    q.push_back(12345);
    cout<<q.back()<<endl;
    // q.pop_back();
    // cout<<q.back()<<endl;
    cout<<q.size();
    

return 0;
}