#include<iostream>
#include<stack>
using namespace std;


void InsertAtEnd(stack<int> &st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }

    int copy = st.top();
    st.pop();

    InsertAtEnd(st,element);

    st.push(copy);
    return;
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int copy = st.top();
    st.pop();

    reverseStack(st);

    InsertAtEnd(st,copy);
    return;
}

int main(){

    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);

    cout<<st.top()<<endl;
    reverseStack(st);
    cout<<st.top();
    

return 0;
}