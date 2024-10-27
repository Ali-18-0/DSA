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
};

class Stack{
    int size;
    node* top;
    int currsize;
    public:
    Stack(int s){
        size = s;
        top = NULL;
        currsize = 0;
    }
    Stack(){
        size = -1;
        currsize = 0;
    }
    ~Stack(){
        while(top != NULL){
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int data){
        if(size == currsize){
            cout<<"Stack OverFlow\n";
        } else {
            currsize++;
            node* temp = new node(data);
            temp->next = top;
            top = temp;
        }

    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack UnderFlow\n";
            return -1;
        }
        node* temp = top;
        top = top->next;
        int cp = temp->data;
        delete temp;
        currsize--;
        return cp;
    }

    bool isEmpty(){
        return top == NULL;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return -1;
        } else {
            return top->data;
        }
    }
    

void Display(){
    cout<<"Stack Data : ";
    node* temp = top;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}
};


int main(){

    Stack a(5);
    a.push(9);
    a.push(7);
    a.push(5);
    a.push(3);
    a.Display();
    a.pop();
    a.Display();
    a.pop();
    a.Display();
    a.pop();
    a.Display();
    a.pop();
    a.Display();
    a.pop();
    a.push(1);
    a.push(1);
    a.push(1);
    a.push(1);
    a.push(1);
    a.push(1);

return 0;
}