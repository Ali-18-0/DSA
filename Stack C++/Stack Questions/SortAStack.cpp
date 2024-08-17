#include<iostream>
#include<stack>
using namespace std;

void display(stack<int> a){
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<endl;
}

void sorted(stack<int> &a,int element){
    if(a.empty()){
        a.push(element);
        return;
    }

    if(element>a.top()){
        a.push(element);
        return;
    }

    int copy = a.top();
    a.pop();

    sorted(a,element);

    a.push(copy);
    return;
}

void sortedSatck(stack<int> &a){
    if(a.empty()){
        return;
    }

    int copy = a.top();
    a.pop();

    sortedSatck(a);

    sorted(a,copy);
    return;
}

int main(){

    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(2);
    st.push(7);
    st.push(4);
    st.push(11);

    display(st);
    // sortedSatck(st);
    // display(st);
    st.pop();
    cout<<st.top();






return 0;
}