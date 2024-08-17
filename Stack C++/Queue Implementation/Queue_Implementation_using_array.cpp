#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int size;
    int fronte;
    int rear;
public:
    Queue(){
        size = 10000;
        arr = new int[size];
        fronte = 0;
        rear = 0;
    }
    Queue(int size){
        this->size = size;
        arr = new int[size];
        fronte = 0;
        rear = 0;
    }
    ~Queue(){
        delete[] arr;
    }

    int Size(){
        if(fronte == rear){
            cout<<"Queue is Empty \n";
            return -1;
        }

        return (rear - fronte);
    }

    int front(){
        if(fronte == rear){
            cout<<"Queue is Empty \n";
            return -1;
        }
        return arr[fronte];
    }
    int back(){
        if(fronte == rear){
            cout<<"Queue is Empty \n";
            return -1;
        }
        return arr[rear-1];
    }

    void push(int a){
        if(rear == size){
            cout<<"Queue is FULL\n";
        }
        arr[rear] = a;
        rear++;
    }

    void pop(){
        if(fronte == rear){
            cout<<"Queue is Empty \n";
            return;
        } 

        arr[fronte] == -1;
        fronte++;
        if(fronte == rear){
            fronte = 0;
            rear = 0;
        }
    }

    bool isempty(){
        if(fronte == rear){
            return true;
        }
        return false;
    }



};

int main(){

    Queue q;
    q.push(5);
    q.push(3);
    q.push(7);
    q.push(13);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.Size()<<endl;
    cout<<q.isempty()<<endl;


return 0;
}