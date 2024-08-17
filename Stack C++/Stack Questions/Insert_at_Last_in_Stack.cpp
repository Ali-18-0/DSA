#include<iostream>
#include<stack>
using namespace std;



void insertAtLast_Stack(stack<int> &st,int element){
    
    if(st.empty()){
        st.push(element);
        return;
    }

    int copy = st.top();
    st.pop();

    insertAtLast_Stack(st,element);

    st.push(copy);

    return;
}

int main(){

    stack<int> st;
    st.push(6);
    st.push(4);

    insertAtLast_Stack(st,5);
    cout<<st.top()<<endl;

    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;


return 0;
}