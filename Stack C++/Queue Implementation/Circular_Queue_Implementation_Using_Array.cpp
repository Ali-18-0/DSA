#include<iostream>
using namespace std;

class QUEUE_CIRCULAR{
    int* arr;
    int n;
    int frontt;
    int rear;

public:
    QUEUE_CIRCULAR(){
        n = 10000;
        arr = new int[n];
        frontt = -1;
        rear = -1;
    }

    QUEUE_CIRCULAR(int size){
        n = size;
        arr = new int[n];
        frontt = -1;
        rear = -1;
    }

    ~QUEUE_CIRCULAR(){
        delete[] arr;
    }

    bool isEmpty(){
        if(frontt == -1 && rear == -1){
            return true;
        }
        return false;
    }

    int front(){
        if(!isEmpty()){
            return arr[frontt];
        }
        cout<<"Queue is Empty \n";
        return -1;
    }

    int back(){
        if(!isEmpty()){
            return arr[rear];
        }
        cout<<"Queue is Empty \n";
        return -1;
    }

    void push(int a){
        if((frontt == 0 && rear == n-1) || (rear == ((frontt-1)%(n-1)))){
            cout<<"Queue is Full \n";
        } else if(rear == n-1 && frontt!=0){
            rear = 0;
            arr[rear] = a;
        }else if(isEmpty()){
            frontt = rear = 0;
            arr[rear] = a;
        } else {
            rear++;
            arr[rear] = a;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty \n";
            return;
        }
        arr[frontt] = -1;

        if(frontt == rear){
            frontt = rear = -1;
        } else if(frontt == n-1){
            frontt = 0;
        } else {
            frontt++;
        }
    }

    int size(){
        int ans;
        if(rear>=frontt){
            ans = (rear - frontt)+1;
        } else {
            ans = (rear+1) + (n - frontt);
        }
    return ans;
    }
};


int main(){

    QUEUE_CIRCULAR q(4);
    q.push(5);
    q.push(3);
    q.push(11);
    q.push(17);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.push(111);
    q.pop();
    cout<<q.front()<<endl;
    q.push(111);
    cout<<q.size()<<endl;
    q.push(19);


return 0;
}