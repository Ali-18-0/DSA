#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    ~Stack(){
        delete[] arr;
        cout<<"DESTRUCTOR CALLED\nTHE END";
    }

    void push(int v){
        if((size - top)>1){
            top++;
            *(arr+top) = v;
        } else {
            cout<<"Stack Overflow "<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        } else {
            cout<<"Stack Underflow "<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return *(arr+top);
        } else {
            cout<<"Stack is Empty "<<endl;;
            return -1;
        }
    }

    bool IsEmpty(){
        if(top == -1){
            return true;
        } else {
            return false;
        }
    }

};

int main(){

    Stack st(5);
    st.push(3);
    st.push(32);
    st.push(56);
    st.push(7);
    st.push(71);
    // st.push(72);

    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();
    
    cout<<st.peek()<<endl;
    st.pop();

    if(st.IsEmpty()){
        cout<<"TRUE"<<endl;
    } else {
        cout<<"FALSE"<<endl;
    }
    st.push(5);
    cout<<st.peek()<<endl;
    if(st.IsEmpty()){
        cout<<"TRUE"<<endl;
    } else {
        cout<<"FALSE"<<endl;
    }

return 0;
}